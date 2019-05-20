/**
 * @file imgui_wrapped.h
 * @brief Public ImGUI C API for users of SSE ImGui
 * @internal
 *
 * This file is part of the Skyrim SE ImGui mod (aka SSE ImGui).
 *
 *   SSE ImGui includes parts licensed under MIT, that is the CImGui and ImGUI
 *   files included in this project. Refer to their individual licenses.
 *
 *   SSE ImGui is free software: you can redistribute it and/or modify it
 *   under the terms of the GNU Lesser General Public License as published
 *   by the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   SSE ImGui is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with SSE ImGui. If not, see <http://www.gnu.org/licenses/>.
 *
 * @endinternal
 *
 * @ingroup Public API
 *
 * @see https://github.com/cimgui/cimgui
 * @see https://github.com/ocornut/imgui
 *
 * @details
 * This file is auto-generated from pre-parsed files of cimgui, which in turn
 * is auto-generated from the ImGui headers. Purpose of this file is to enable
 * ImGui being bundled in a shared library which is explicitly linked.
 * Basically, allow SSE ImGui to exist as SKSE plugin and being shared across
 * many other plugin users. Otherwise everybody who wants to utilize ImGui
 * would have to hold on its own copy in the process memory, which is still
 * possible, but it will consume much more resources.
 *
 * See the #sseimgui_imgui_api() function to create a copy of the pointers set.
 * Note that the pointers calling convention follows the CImGui one, not the 
 * project one.
 */

#ifndef SSEIMGUI_IMGUI_WRAPPED_H
#define SSEIMGUI_IMGUI_WRAPPED_H

/* Prefer the pointer table, and save users from re-exporting each time */

#ifndef   CIMGUI_NO_EXPORT
#  define CIMGUI_NO_EXPORT
#endif
#ifndef   CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#  define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#endif
#include <sse-imgui/cimgui.h>

#include <sse-imgui/platform.h>

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/* Taken from imgui.h itself, as not existing in cimgui.h */

#ifndef SSEIMGUI_DISABLE_IMGUI_MACROS

#define IMGUI_VERSION               "1.70 WIP"
#define IMGUI_VERSION_NUM           16991

#define IM_ARRAYSIZE(_ARR)          ((int)(sizeof(_ARR)/sizeof(*_ARR)))
#define IM_OFFSETOF(_TYPE,_MEMBER)  ((size_t)&(((_TYPE*)0)->_MEMBER))
#define IM_UNUSED(_VAR)             ((void)_VAR)

#define IMGUI_PAYLOAD_TYPE_COLOR_3F     "_COL3F"
#define IMGUI_PAYLOAD_TYPE_COLOR_4F     "_COL4F"

#ifdef IMGUI_USE_BGRA_PACKED_COLOR
#define IM_COL32_R_SHIFT    16
#define IM_COL32_G_SHIFT    8
#define IM_COL32_B_SHIFT    0
#define IM_COL32_A_SHIFT    24
#define IM_COL32_A_MASK     0xFF000000
#else
#define IM_COL32_R_SHIFT    0
#define IM_COL32_G_SHIFT    8
#define IM_COL32_B_SHIFT    16
#define IM_COL32_A_SHIFT    24
#define IM_COL32_A_MASK     0xFF000000
#endif

#define IM_COL32(R,G,B,A)    (((ImU32)(A)<<IM_COL32_A_SHIFT) | ((ImU32)(B)<<IM_COL32_B_SHIFT) | ((ImU32)(G)<<IM_COL32_G_SHIFT) | ((ImU32)(R)<<IM_COL32_R_SHIFT))
#define IM_COL32_WHITE       IM_COL32(255,255,255,255)
#define IM_COL32_BLACK       IM_COL32(0,0,0,255)
#define IM_COL32_BLACK_TRANS IM_COL32(0,0,0,0)

#endif

/******************************************************************************/

/** Holds all CImGui (hence ImGui) functions as pointers */

struct imgui_api_v1
{
%for f in api:
    ${f[0]} (* ${f[1]}) ${f[2]}
%endfor
};

/** Current version of the API. */

typedef struct imgui_api_v1 imgui_api;

/******************************************************************************/

/** Create new #sseimgui_api instance, all method pointers assigned. */

SSEIMGUI_API imgui_api SSEIMGUI_CCONV
sseimgui_make_imgui_api ();

/** @see #sseimgui_make_imgui_api() */

typedef imgui_api (SSEIMGUI_CCONV* sseimgui_make_imgui_api_t) ();

/******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* SSEIMGUI_IMGUI_WRAPPED_H */

/* EOF */

