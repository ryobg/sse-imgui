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

#include <string>
#include <array>
#include <algorithm>
#include <fstream>

#include <windows.h>

//--------------------------------------------------------------------------------------------------

using namespace std::string_literals;

/// Opened from within skse.cpp
extern std::ofstream& log ();

/// [shared] Supports SSE-ImGui specific errors in a manner of #GetLastError() and #FormatMessage()
std::string sseimgui_error;

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
    extern unsigned activation_key (unsigned* optional);
    *vik = (int) activation_key ((*vik >= 0 && *vik < 256) ? (unsigned*) &vik : nullptr);
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
    return api;
}

//--------------------------------------------------------------------------------------------------

