/**
 * @file skse.cpp
 * @brief A SKSE plugin for SSE-ImGui
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
#include <sse-gui/sse-gui.h>
#include <utils/winutils.hpp>

#include <cstdint>
typedef std::uint32_t UInt32;
typedef std::uint64_t UInt64;
#include <skse/PluginAPI.h>

#include <chrono>
#include <fstream>
#include <iomanip>

//--------------------------------------------------------------------------------------------------

/// Given by SKSE to uniquely identify this DLL
static PluginHandle plugin = 0;

/// To communicate with the other SKSE plugins.
static SKSEMessagingInterface* messages = nullptr;

/// Log file in pre-defined location
static std::ofstream logfile;

/// [shared] In order to hook upon D3D11
std::unique_ptr<ssegui_api> ssegui;

//--------------------------------------------------------------------------------------------------

static void
open_log ()
{
    std::string path;
    if (known_folder_path (FOLDERID_Documents, path))
    {
        // Before plugins are loaded, SKSE takes care to create the directiories
        path += "\\My Games\\Skyrim Special Edition\\SKSE\\";
    }
    path += "sse-imgui.log";
    logfile.open (path);
}

//--------------------------------------------------------------------------------------------------

decltype(logfile)&
log ()
{
    // MinGW 4.9.1 have no std::put_time()
    using std::chrono::system_clock;
    auto now_c = system_clock::to_time_t (system_clock::now ());
    auto loc_c = std::localtime (&now_c);
    logfile << '['
            << 1900 + loc_c->tm_year
            << '-' << std::setw (2) << std::setfill ('0') << loc_c->tm_mon
            << '-' << std::setw (2) << std::setfill ('0') << loc_c->tm_mday
            << ' ' << std::setw (2) << std::setfill ('0') << loc_c->tm_hour
            << ':' << std::setw (2) << std::setfill ('0') << loc_c->tm_min
            << ':' << std::setw (2) << std::setfill ('0') << loc_c->tm_sec
        << "] ";
    return logfile;
}

//--------------------------------------------------------------------------------------------------

/// This is somewhere in SKSE Input Loaded message

static void
handle_ssegui_message (SKSEMessagingInterface::Message* m)
{
    if (m->type != SSEGUI_API_VERSION)
    {
        log () << "Unsupported SSEGUI interface v" << m->type
               << " (it is not v" << SSEGUI_API_VERSION
               << "). Bailing out." << std::endl;
        return;
    }

    ssegui.reset (new ssegui_api (*reinterpret_cast<ssegui_api*> (m->data)));
    log () << "Accepted SSEGUI interface v" << SSEGUI_API_VERSION << std::endl;

    extern bool setup_imgui ();
    if (!setup_imgui ())
    {
        log () << "Unable to setup SSE ImGui." << std::endl;
        return;
    }
    log () << "SSE-ImGui setup done." << std::endl;
}

//--------------------------------------------------------------------------------------------------

/// Post Load ensure sse-gui is loaded and can accept listeners

static void
handle_skse_message (SKSEMessagingInterface::Message* m)
{
    if (m->type != SKSEMessagingInterface::kMessage_PostLoad)
        return;
    messages->RegisterListener (plugin, "SSEGUI", handle_ssegui_message);
}

//--------------------------------------------------------------------------------------------------

/// @see SKSE.PluginAPI.h

extern "C" SSEIMGUI_API bool SSEIMGUI_CCONV
SKSEPlugin_Query (SKSEInterface const* skse, PluginInfo* info)
{
    info->infoVersion = PluginInfo::kInfoVersion;
    info->name = "SSEIMGUI";
    info->version = SSEIMGUI_API_VERSION;

    plugin = skse->GetPluginHandle ();

    if (skse->isEditor)
        return false;

    return true;
}

//--------------------------------------------------------------------------------------------------

/// @see SKSE.PluginAPI.h

extern "C" SSEIMGUI_API bool SSEIMGUI_CCONV
SKSEPlugin_Load (SKSEInterface const* skse)
{
    open_log ();

    messages = (SKSEMessagingInterface*) skse->QueryInterface (kInterface_Messaging);
    messages->RegisterListener (plugin, "SKSE", handle_skse_message);

    int a, m, p;
    const char* b;
    sseimgui_version (&a, &m, &p, &b);
    log () << "SSE-ImGui "<< a <<'.'<< m <<'.'<< p <<" ("<< b <<')' << std::endl;
    return true;
}

//--------------------------------------------------------------------------------------------------


