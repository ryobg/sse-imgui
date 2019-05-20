/**
 * @file render.cpp
 * @internal
 *
 * This file is part of Skyrim SE ImGui mod project (aka SSE-ImGui).
 *
 *   SSE-ImGui is free software: you can redistribute it and/or modify it
 *   under the terms of the GNU Lesser General Public License as published
 *   by the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   SSE-ImGui is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with SSE-ImGui. If not, see <http://www.gnu.org/licenses/>.
 *
 * @endinternal
 *
 * @ingroup Public API
 *
 * @details
 * All related to DirectX, window handling and actual rendering of GUI elements.
 */

#include <sse-imgui/platform.h>
#include <sse-gui/sse-gui.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_impl_dx11.h>
#include <gsl/gsl_util>
#include <gsl/span>
#include <utils/winutils.hpp>

#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <fstream>
#include <mutex>

#include <windows.h>
#include <dwmapi.h>
#include <d3d11.h>

//--------------------------------------------------------------------------------------------------

using namespace std::string_literals;

/// Opened from within skse.cpp
extern std::ofstream& log ();

/// Defined in sse-imgui.cpp
extern std::string sseimgui_error;

/// Defined in skse.cpp
extern std::unique_ptr<ssegui_api> ssegui;

/// All in one holder of DirectX & Co. fields
struct render_t
{
    ID3D11Device*           device;
    ID3D11DeviceContext*    context;
    IDXGISwapChain*         chain;
    ID3D11RenderTargetView* view;
    HWND                    window;

    ImGuiContext* imgui_context;
    bool imgui_win32;
    bool imgui_dx11;
    bool render;
    unsigned activation_key;

    bool d3dcompile_failed;
    HMODULE d3dcompile_library;
    HRESULT (WINAPI *d3dcompile) (
        LPCVOID, SIZE_T, LPCSTR, D3D_SHADER_MACRO*, ID3DInclude*, LPCSTR,
        LPCSTR, UINT, UINT, ID3DBlob**, ID3DBlob*);

    std::vector<void (SSEIMGUI_CCONV*)(int)> render_listeners;
};

/// One and only one object
static render_t dx = {};

//--------------------------------------------------------------------------------------------------

static LRESULT CALLBACK window_proc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static void WINAPI chain_present (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);

static void cleanup_dx ()
{
    ssegui->render_listener ((ssegui_render_callback) &chain_present, true);
    ssegui->message_listener ((ssegui_message_callback) &window_proc, true);

    if (dx.imgui_dx11)
    {
         ImGui_ImplDX11_Shutdown ();
         dx.imgui_dx11 = false;
    }
    if (dx.imgui_win32)
    {
         ImGui_ImplWin32_Shutdown ();
         dx.imgui_win32 = false;
    }
    if (dx.imgui_context)
        ImGui::DestroyContext (std::exchange (dx.imgui_context, nullptr));

    if (dx.view) std::exchange (dx.view, nullptr)->Release ();

    if (dx.d3dcompile_library) ::FreeLibrary (std::exchange (dx.d3dcompile_library, nullptr));
}

//--------------------------------------------------------------------------------------------------

static LRESULT CALLBACK
window_proc (HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_KEYUP && wParam == dx.activation_key)
    {
        dx.render = !dx.render;
        ImGui::GetIO ().MouseDrawCursor = dx.render;
    }
    LRESULT ret = 0;
    if (dx.render)
    {
        extern LRESULT ImGui_ImplWin32_WndProcHandler (HWND, UINT, WPARAM, LPARAM);
        ret = ImGui_ImplWin32_WndProcHandler (hWnd,  msg, wParam, lParam);
    }
    return ret;
}

//--------------------------------------------------------------------------------------------------

static void WINAPI
chain_present (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
    ImGui_ImplDX11_NewFrame ();
    ImGui_ImplWin32_NewFrame ();
    ImGui::NewFrame ();

    if (!dx.render)
        ImGui::GetIO ().MousePos = ImVec2 (-FLT_MAX, -FLT_MAX);

    for (auto const& l: dx.render_listeners)
        l (dx.render);

    ImGui::Render ();
    dx.context->OMSetRenderTargets (1, &dx.view, nullptr);
    ImGui_ImplDX11_RenderDrawData (ImGui::GetDrawData ());
}

//--------------------------------------------------------------------------------------------------

/// void* as too lazy to type the type when needed.

void
update_render_listener (void* callback, bool remove)
{
    auto& list = dx.render_listeners;
    auto l = reinterpret_cast<decltype (dx.render_listeners)::value_type> (callback);
    if (remove)
    {
        list.erase (std::remove (list.begin (), list.end (),  l));
        log () << "Render callback " << callback << " removed." << std::endl;
    }
    else if (std::find (list.cbegin (), list.cend (), l) == list.cend ())
    {
        list.push_back (l);
        log () << "Render callback " << callback << " added." << std::endl;
    }
}

//--------------------------------------------------------------------------------------------------

unsigned
activation_key (unsigned* optional)
{
    Expects (!optional || *optional < 256);
    return std::exchange (dx.activation_key, optional ? *optional : dx.activation_key);
}

//--------------------------------------------------------------------------------------------------

bool
setup_imgui ()
{
    if (!ssegui->parameter ("ID3D11Device", &dx.device)
            || !ssegui->parameter ("ID3D11DeviceContext", &dx.context)
            || !ssegui->parameter ("IDXGISwapChain", &dx.chain)
            || !ssegui->parameter ("window", &dx.window)
            )
    {
        sseimgui_error = __func__ + " unable to obtain SSE-GUI parameters"s;
        return false;
    }

    bool do_cleanup = true;
    auto cleanup = gsl::finally ([&do_cleanup] { if (do_cleanup) cleanup_dx (); });

    ID3D11Texture2D* back = nullptr;
    dx.chain->GetBuffer (0, IID_PPV_ARGS (&back));
    dx.device->CreateRenderTargetView (back, NULL, &dx.view);
    back->Release ();

    IMGUI_CHECKVERSION ();
    dx.imgui_context = ImGui::CreateContext ();
    ImGuiIO& io = ImGui::GetIO ();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    ImGui::StyleColorsDark ();
    dx.imgui_win32 = ImGui_ImplWin32_Init (dx.window);
    dx.imgui_dx11 = ImGui_ImplDX11_Init (dx.device, dx.context);
    io.Fonts->AddFontDefault ();

    if (!dx.imgui_win32 || !dx.imgui_dx11)
    {
        sseimgui_error = __func__ + " unable to init ImGui modules"s;
        return false;
    }

    ssegui->render_listener ((ssegui_render_callback) &chain_present, false);
    ssegui->message_listener ((ssegui_message_callback) &window_proc, false);

    dx.activation_key = VK_INSERT;
    do_cleanup = false;
    return true;
}

//--------------------------------------------------------------------------------------------------

/// Avoid build time linking to a d3dcompiler library (as required by ImGUI). It is not very clear
/// which verion an user will have.

HRESULT WINAPI D3DCompile (
        LPCVOID p1, SIZE_T p2, LPCSTR p3, D3D_SHADER_MACRO* p4, ID3DInclude* p5, LPCSTR p6,
        LPCSTR p7, UINT p8, UINT p9, ID3DBlob** p10, ID3DBlob* p11)
{
    if (dx.d3dcompile_failed)
        return TYPE_E_ELEMENTNOTFOUND;

    if (!dx.d3dcompile)
    {
        sseimgui_error.clear ();
        std::string name;
        HMODULE dll = nullptr;
        for (int i = 50; i > 30 && !dll; --i)
        {
            name = "D3DCompiler_" + std::to_string (i) + ".dll";
            dll = ::LoadLibraryA (name.c_str ());
        }
        if (!dll)
        {
            dx.d3dcompile_failed = true;
            sseimgui_error = __func__ + " unable to load d3dcompiler_XX.dll"s;
            log () << sseimgui_error << std::endl;
            return TYPE_E_ELEMENTNOTFOUND;
        }
        dx.d3dcompile = (decltype (dx.d3dcompile)) ::GetProcAddress (dll, "D3DCompile");
        if (!dx.d3dcompile)
        {
            ::FreeLibrary (dll);
            dx.d3dcompile_failed = true;
            sseimgui_error = __func__ + " unable to find D3DCompile in "s + name;
            log () << sseimgui_error << std::endl;
            return TYPE_E_ELEMENTNOTFOUND;
        }
        dx.d3dcompile_library = dll;
        log () << "D3DCompile@" << name << " loaded." << std::endl;
    }

    return dx.d3dcompile (p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
}

//--------------------------------------------------------------------------------------------------

