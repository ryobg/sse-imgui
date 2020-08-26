/**
 * @file sse-imgui.cpp
 * @copybrief sse-imgui.h
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
 * Implements the public API.
 */

#include <sse-imgui/sse-imgui.h>
#include <utils/winutils.hpp>
#include <sse-gui/sse-gui.h>
#include <DDSTextureLoader/DDSTextureLoader.h>

#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <fstream>
#include <memory>

#include <windows.h>

//--------------------------------------------------------------------------------------------------

using namespace std::string_literals;

/// Opened from within skse.cpp
extern std::ofstream& log ();

/// [shared] Supports SSE-ImGui specific errors in a manner of #GetLastError() and #FormatMessage()
std::string sseimgui_error;

/// Defined in skse.cpp
extern std::unique_ptr<ssegui_api> ssegui;

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

SSEIMGUI_API void SSEIMGUI_CCONV
sseimgui_version (int* api, int* maj, int* imp, const char** build)
{
    constexpr std::array<int, 3> ver = {
#include "../VERSION"
    };
    if (api) *api = ver[0];
    if (maj) *maj = ver[1];
    if (imp) *imp = ver[2];
    if (build) *build = SSEIMGUI_TIMESTAMP; //"2019-04-15T08:37:11.419416+00:00"
    static_assert (ver[0] == SSEIMGUI_API_VERSION, "API in VERSION and sse-hooks.h must match");
}

//--------------------------------------------------------------------------------------------------

SSEIMGUI_API void SSEIMGUI_CCONV
sseimgui_last_error (size_t* size, char* message)
{
    if (sseimgui_error.size ())
    {
        copy_string (sseimgui_error, size, message);
        return;
    }

    auto err = ::GetLastError ();
    if (!err)
    {
        *size = 0;
        if (message) *message = 0;
        return;
    }

    copy_string (format_utf8message (err), size, message);
}

//--------------------------------------------------------------------------------------------------

SSEIMGUI_API void SSEIMGUI_CCONV
sseimgui_activation_key (int* vik)
{
    (void) vik;
    sseimgui_error = __func__ + " is deprecated"s;
}

//--------------------------------------------------------------------------------------------------

SSEIMGUI_API void SSEIMGUI_CCONV
sseimgui_render_listener (sseimgui_render_callback callback, int remove)
{
    extern void update_render_listener (void* callback, bool remove);
    update_render_listener ((void*) callback, !!remove);
}

//--------------------------------------------------------------------------------------------------

SSEIMGUI_API int SSEIMGUI_CCONV
sseimgui_execute (const char* command, void* arg)
{
    return false;
}

//--------------------------------------------------------------------------------------------------

SSEIMGUI_API int SSEIMGUI_CCONV
sseimgui_ddsfile_texture (const char* filename, void* texture, void* view)
{
    ID3D11Device* device = nullptr;
    ID3D11DeviceContext* context = nullptr;
    ID3D11Resource* resource = nullptr;
    ID3D11ShaderResourceView* resource_view = nullptr;

    if (!ssegui->parameter ("ID3D11Device", &device)
            || !ssegui->parameter ("ID3D11DeviceContext", &context))
    {
        sseimgui_error = __func__ + " unable to obtain SSE-Gui parameters"s;
        return false;
    }

    std::wstring w;
    if (!utf8_to_utf16 (filename, w))
    {
        sseimgui_error = __func__ + " unable to convert filename to UTF-16"s;
        return false;
    }

    HRESULT hres = DirectX::CreateDDSTextureFromFile (
            device, context, w.c_str (), &resource, &resource_view, 0, nullptr);
    if (FAILED (hres))
    {
        sseimgui_error = __func__ + " CreateDDSTextureFromFile "s + hex_string (hres);
        return false;
    }

    if (texture) *((ID3D11Resource**) texture) = resource;
    if (view) *((ID3D11ShaderResourceView**) view) = resource_view;
    return true;
}

//--------------------------------------------------------------------------------------------------

SSEIMGUI_API int SSEIMGUI_CCONV
sseimgui_compress_font (const char* filename, char* out, size_t* size)
{
    extern bool binary_to_compressed_c (const char*, const char*, bool, bool, std::vector<char>&);

    std::vector<char> buff;
    if (!binary_to_compressed_c (filename, nullptr, true, true, buff))
    {
        sseimgui_error = __func__ + " binary_to_compressed_c failed."s;
        return false;
    }
    buff.push_back (0);

    if (out) std::copy_n (buff.cbegin (), std::min (*size, buff.size ()), out);
    *size = buff.size ();
    return true;
}

//--------------------------------------------------------------------------------------------------

SSEIMGUI_API sseimgui_api SSEIMGUI_CCONV
sseimgui_make_api ()
{
    sseimgui_api api    = {};
    api.version         = sseimgui_version;
    api.last_error      = sseimgui_last_error;
    api.activation_key  = sseimgui_activation_key;
    api.render_listener = sseimgui_render_listener;
    api.make_imgui_api  = sseimgui_make_imgui_api;
    api.execute         = sseimgui_execute;
    api.ddsfile_texture = sseimgui_ddsfile_texture;
    api.compress_font   = sseimgui_compress_font;
    return api;
}

//--------------------------------------------------------------------------------------------------

