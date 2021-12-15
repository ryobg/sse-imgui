/**
 * @file demo.cpp
 * @brief A demonstration SKSE plugin for SSE-ImGui
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
 * This file only depends on one header file provided by SKSE. As it looks, that plugin interface
 * does not change much, if at all. Hence, this means there is stable interface which can make
 * SSE-ImGui version independent of SKSE. This file by itself is standalone enough so it can be a
 * separate DLL project - binding SSE-ImGui to SKSE.
 */

#include <sse-imgui/sse-imgui.h>

#include <cstdint>
typedef std::uint32_t UInt32;
typedef std::uint64_t UInt64;
#include "PluginAPI.h"

//--------------------------------------------------------------------------------------------------

/// Given by SKSE to uniquely identify this DLL
static PluginHandle plugin = 0;

/// To communicate with the other SKSE plugins.
static SKSEMessagingInterface* messages = nullptr;

/// Table with pointers
imgui_api imgui;

//--------------------------------------------------------------------------------------------------

static void SSEIMGUI_CCONV
render (int active)
{
    if (!active)
        return;

    static bool show_demo_window = true;
    static bool show_another_window = false;

    if (show_demo_window)
        imgui.igShowDemoWindow (&show_demo_window);
    {
        static float f = 0.0f;
        static int counter = 0;
        imgui.igBegin ("Hello, world!", nullptr, 0);
        imgui.igText ("This is some useful text.");
        imgui.igCheckbox ("Demo Window", &show_demo_window);
        imgui.igCheckbox ("Another Window", &show_another_window);
        imgui.igSliderFloat ("float", &f, 0.0f, 1.0f, "%.3f", 1.f);
        if (imgui.igButton ("Button", ImVec2 {}))
            counter++;
        imgui.igSameLine (0.f, -1.f);
        imgui.igText ("counter = %d", counter);
        imgui.igText ("Application average %.3f ms/frame (%.1f FPS)",
                1000.0f / imgui.igGetIO ()->Framerate, imgui.igGetIO ()->Framerate);
        imgui.igEnd ();
    }
    if (show_another_window)
    {
        imgui.igBegin ("Another Window", &show_another_window, 0);
        imgui.igText ("Hello from another window!");
        if (imgui.igButton ("Close Me", ImVec2 {}))
            show_another_window = false;
        imgui.igEnd ();
    }
}

//--------------------------------------------------------------------------------------------------

static void
handle_sseimgui_message (SKSEMessagingInterface::Message* m)
{
    if (m->type != SSEIMGUI_API_VERSION)
        return;

    sseimgui_api* sseimgui = reinterpret_cast<sseimgui_api*> (m->data);
    sseimgui->render_listener (&render, 0);
    imgui = sseimgui->make_imgui_api ();
}

//--------------------------------------------------------------------------------------------------

/// Post Load ensure SSEIMGUI is loaded and can accept listeners

static void
handle_skse_message (SKSEMessagingInterface::Message* m)
{
    if (m->type != SKSEMessagingInterface::kMessage_PostLoad)
        return;
    messages->RegisterListener (plugin, "SSEIMGUI", handle_sseimgui_message);
}

//--------------------------------------------------------------------------------------------------

/// @see SKSE.PluginAPI.h

extern "C" {

__declspec(dllexport) SKSEPluginVersionData SKSEPlugin_Version =
{
    SKSEPluginVersionData::kVersion,
    2,
    "sse-imgui-demo",
    "ryobg",
    "",
    SKSEPluginVersionData::kVersionIndependent_Signatures, // Disables the compatibleVersions checks
    { 0 },
    0,  // > PACKED_SKSE_VERSION i.e. works with any version of SKSE
};

}

//--------------------------------------------------------------------------------------------------

/// @see SKSE.PluginAPI.h

extern "C" __declspec(dllexport) bool SSEIMGUI_CCONV
SKSEPlugin_Load (SKSEInterface const* skse)
{
    plugin = skse->GetPluginHandle ();
    messages = (SKSEMessagingInterface*) skse->QueryInterface (kInterface_Messaging);
    messages->RegisterListener (plugin, "SKSE", handle_skse_message);
    return true;
}

//--------------------------------------------------------------------------------------------------


