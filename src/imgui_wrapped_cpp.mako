/**
 * @file imgui_wrapped.c
 * @copybrief imgui_wrapped.h
 * @internal
 *
 * This file is part of Skyrim SE ImGui mod (aka SSEImGui).
 *
 *   SSEImGui includes parts licensed under MIT, that is the cimgui and ImGUI
 *   files included in this project. Refer to their individual licenses.
 *
 *   SSGImGUI is free software: you can redistribute it and/or modify it
 *   under the terms of the GNU Lesser General Public License as published
 *   by the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   SSEImGUI is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with SSEImGUI. If not, see <http://www.gnu.org/licenses/>.
 *
 * @endinternal
 *
 * @ingroup Public API
 */

#include <sse-imgui/imgui_wrapped.h>

/******************************************************************************/

imgui_api
sseimgui_make_imgui_api ()
{
    imgui_api v = {};
%for n in names:
    v.${n} = &${n};
%endfor
    return v;
}

/******************************************************************************/

