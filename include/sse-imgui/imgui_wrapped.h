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
    ImVec2* (* ImVec2_ImVec2) (void);
    void (* ImVec2_destroy) (ImVec2* self);
    ImVec2* (* ImVec2_ImVec2Float) (float _x,float _y);
    ImVec4* (* ImVec4_ImVec4) (void);
    void (* ImVec4_destroy) (ImVec4* self);
    ImVec4* (* ImVec4_ImVec4Float) (float _x,float _y,float _z,float _w);
    ImGuiContext* (* igCreateContext) (ImFontAtlas* shared_font_atlas);
    void (* igDestroyContext) (ImGuiContext* ctx);
    ImGuiContext* (* igGetCurrentContext) (void);
    void (* igSetCurrentContext) (ImGuiContext* ctx);
    bool (* igDebugCheckVersionAndDataLayout) (const char* version_str,size_t sz_io,size_t sz_style,size_t sz_vec2,size_t sz_vec4,size_t sz_drawvert,size_t sz_drawidx);
    ImGuiIO* (* igGetIO) (void);
    ImGuiStyle* (* igGetStyle) (void);
    void (* igNewFrame) (void);
    void (* igEndFrame) (void);
    void (* igRender) (void);
    ImDrawData* (* igGetDrawData) (void);
    void (* igShowDemoWindow) (bool* p_open);
    void (* igShowAboutWindow) (bool* p_open);
    void (* igShowMetricsWindow) (bool* p_open);
    void (* igShowStyleEditor) (ImGuiStyle* ref);
    bool (* igShowStyleSelector) (const char* label);
    void (* igShowFontSelector) (const char* label);
    void (* igShowUserGuide) (void);
    const char* (* igGetVersion) (void);
    void (* igStyleColorsDark) (ImGuiStyle* dst);
    void (* igStyleColorsClassic) (ImGuiStyle* dst);
    void (* igStyleColorsLight) (ImGuiStyle* dst);
    bool (* igBegin) (const char* name,bool* p_open,ImGuiWindowFlags flags);
    void (* igEnd) (void);
    bool (* igBeginChild) (const char* str_id,const ImVec2 size,bool border,ImGuiWindowFlags flags);
    bool (* igBeginChildID) (ImGuiID id,const ImVec2 size,bool border,ImGuiWindowFlags flags);
    void (* igEndChild) (void);
    bool (* igIsWindowAppearing) (void);
    bool (* igIsWindowCollapsed) (void);
    bool (* igIsWindowFocused) (ImGuiFocusedFlags flags);
    bool (* igIsWindowHovered) (ImGuiHoveredFlags flags);
    ImDrawList* (* igGetWindowDrawList) (void);
    ImVec2 (* igGetWindowPos) (void);
    ImVec2 (* igGetWindowSize) (void);
    float (* igGetWindowWidth) (void);
    float (* igGetWindowHeight) (void);
    void (* igSetNextWindowPos) (const ImVec2 pos,ImGuiCond cond,const ImVec2 pivot);
    void (* igSetNextWindowSize) (const ImVec2 size,ImGuiCond cond);
    void (* igSetNextWindowSizeConstraints) (const ImVec2 size_min,const ImVec2 size_max,ImGuiSizeCallback custom_callback,void* custom_callback_data);
    void (* igSetNextWindowContentSize) (const ImVec2 size);
    void (* igSetNextWindowCollapsed) (bool collapsed,ImGuiCond cond);
    void (* igSetNextWindowFocus) (void);
    void (* igSetNextWindowBgAlpha) (float alpha);
    void (* igSetWindowPosVec2) (const ImVec2 pos,ImGuiCond cond);
    void (* igSetWindowSizeVec2) (const ImVec2 size,ImGuiCond cond);
    void (* igSetWindowCollapsedBool) (bool collapsed,ImGuiCond cond);
    void (* igSetWindowFocus) (void);
    void (* igSetWindowFontScale) (float scale);
    void (* igSetWindowPosStr) (const char* name,const ImVec2 pos,ImGuiCond cond);
    void (* igSetWindowSizeStr) (const char* name,const ImVec2 size,ImGuiCond cond);
    void (* igSetWindowCollapsedStr) (const char* name,bool collapsed,ImGuiCond cond);
    void (* igSetWindowFocusStr) (const char* name);
    ImVec2 (* igGetContentRegionMax) (void);
    ImVec2 (* igGetContentRegionAvail) (void);
    ImVec2 (* igGetWindowContentRegionMin) (void);
    ImVec2 (* igGetWindowContentRegionMax) (void);
    float (* igGetWindowContentRegionWidth) (void);
    float (* igGetScrollX) (void);
    float (* igGetScrollY) (void);
    float (* igGetScrollMaxX) (void);
    float (* igGetScrollMaxY) (void);
    void (* igSetScrollX) (float scroll_x);
    void (* igSetScrollY) (float scroll_y);
    void (* igSetScrollHereY) (float center_y_ratio);
    void (* igSetScrollFromPosY) (float local_y,float center_y_ratio);
    void (* igPushFont) (ImFont* font);
    void (* igPopFont) (void);
    void (* igPushStyleColorU32) (ImGuiCol idx,ImU32 col);
    void (* igPushStyleColor) (ImGuiCol idx,const ImVec4 col);
    void (* igPopStyleColor) (int count);
    void (* igPushStyleVarFloat) (ImGuiStyleVar idx,float val);
    void (* igPushStyleVarVec2) (ImGuiStyleVar idx,const ImVec2 val);
    void (* igPopStyleVar) (int count);
    const ImVec4* (* igGetStyleColorVec4) (ImGuiCol idx);
    ImFont* (* igGetFont) (void);
    float (* igGetFontSize) (void);
    ImVec2 (* igGetFontTexUvWhitePixel) (void);
    ImU32 (* igGetColorU32) (ImGuiCol idx,float alpha_mul);
    ImU32 (* igGetColorU32Vec4) (const ImVec4 col);
    ImU32 (* igGetColorU32U32) (ImU32 col);
    void (* igPushItemWidth) (float item_width);
    void (* igPopItemWidth) (void);
    void (* igSetNextItemWidth) (float item_width);
    float (* igCalcItemWidth) (void);
    void (* igPushTextWrapPos) (float wrap_local_pos_x);
    void (* igPopTextWrapPos) (void);
    void (* igPushAllowKeyboardFocus) (bool allow_keyboard_focus);
    void (* igPopAllowKeyboardFocus) (void);
    void (* igPushButtonRepeat) (bool repeat);
    void (* igPopButtonRepeat) (void);
    void (* igSeparator) (void);
    void (* igSameLine) (float offset_from_start_x,float spacing);
    void (* igNewLine) (void);
    void (* igSpacing) (void);
    void (* igDummy) (const ImVec2 size);
    void (* igIndent) (float indent_w);
    void (* igUnindent) (float indent_w);
    void (* igBeginGroup) (void);
    void (* igEndGroup) (void);
    ImVec2 (* igGetCursorPos) (void);
    float (* igGetCursorPosX) (void);
    float (* igGetCursorPosY) (void);
    void (* igSetCursorPos) (const ImVec2 local_pos);
    void (* igSetCursorPosX) (float local_x);
    void (* igSetCursorPosY) (float local_y);
    ImVec2 (* igGetCursorStartPos) (void);
    ImVec2 (* igGetCursorScreenPos) (void);
    void (* igSetCursorScreenPos) (const ImVec2 pos);
    void (* igAlignTextToFramePadding) (void);
    float (* igGetTextLineHeight) (void);
    float (* igGetTextLineHeightWithSpacing) (void);
    float (* igGetFrameHeight) (void);
    float (* igGetFrameHeightWithSpacing) (void);
    void (* igPushIDStr) (const char* str_id);
    void (* igPushIDRange) (const char* str_id_begin,const char* str_id_end);
    void (* igPushIDPtr) (const void* ptr_id);
    void (* igPushIDInt) (int int_id);
    void (* igPopID) (void);
    ImGuiID (* igGetIDStr) (const char* str_id);
    ImGuiID (* igGetIDRange) (const char* str_id_begin,const char* str_id_end);
    ImGuiID (* igGetIDPtr) (const void* ptr_id);
    void (* igTextUnformatted) (const char* text,const char* text_end);
    void (* igText) (const char* fmt,...);
    void (* igTextV) (const char* fmt,va_list args);
    void (* igTextColored) (const ImVec4 col,const char* fmt,...);
    void (* igTextColoredV) (const ImVec4 col,const char* fmt,va_list args);
    void (* igTextDisabled) (const char* fmt,...);
    void (* igTextDisabledV) (const char* fmt,va_list args);
    void (* igTextWrapped) (const char* fmt,...);
    void (* igTextWrappedV) (const char* fmt,va_list args);
    void (* igLabelText) (const char* label,const char* fmt,...);
    void (* igLabelTextV) (const char* label,const char* fmt,va_list args);
    void (* igBulletText) (const char* fmt,...);
    void (* igBulletTextV) (const char* fmt,va_list args);
    bool (* igButton) (const char* label,const ImVec2 size);
    bool (* igSmallButton) (const char* label);
    bool (* igInvisibleButton) (const char* str_id,const ImVec2 size);
    bool (* igArrowButton) (const char* str_id,ImGuiDir dir);
    void (* igImage) (ImTextureID user_texture_id,const ImVec2 size,const ImVec2 uv0,const ImVec2 uv1,const ImVec4 tint_col,const ImVec4 border_col);
    bool (* igImageButton) (ImTextureID user_texture_id,const ImVec2 size,const ImVec2 uv0,const ImVec2 uv1,int frame_padding,const ImVec4 bg_col,const ImVec4 tint_col);
    bool (* igCheckbox) (const char* label,bool* v);
    bool (* igCheckboxFlags) (const char* label,unsigned int* flags,unsigned int flags_value);
    bool (* igRadioButtonBool) (const char* label,bool active);
    bool (* igRadioButtonIntPtr) (const char* label,int* v,int v_button);
    void (* igProgressBar) (float fraction,const ImVec2 size_arg,const char* overlay);
    void (* igBullet) (void);
    bool (* igBeginCombo) (const char* label,const char* preview_value,ImGuiComboFlags flags);
    void (* igEndCombo) (void);
    bool (* igCombo) (const char* label,int* current_item,const char* const items[],int items_count,int popup_max_height_in_items);
    bool (* igComboStr) (const char* label,int* current_item,const char* items_separated_by_zeros,int popup_max_height_in_items);
    bool (* igComboFnPtr) (const char* label,int* current_item,bool(*items_getter)(void* data,int idx,const char** out_text),void* data,int items_count,int popup_max_height_in_items);
    bool (* igDragFloat) (const char* label,float* v,float v_speed,float v_min,float v_max,const char* format,float power);
    bool (* igDragFloat2) (const char* label,float v[2],float v_speed,float v_min,float v_max,const char* format,float power);
    bool (* igDragFloat3) (const char* label,float v[3],float v_speed,float v_min,float v_max,const char* format,float power);
    bool (* igDragFloat4) (const char* label,float v[4],float v_speed,float v_min,float v_max,const char* format,float power);
    bool (* igDragFloatRange2) (const char* label,float* v_current_min,float* v_current_max,float v_speed,float v_min,float v_max,const char* format,const char* format_max,float power);
    bool (* igDragInt) (const char* label,int* v,float v_speed,int v_min,int v_max,const char* format);
    bool (* igDragInt2) (const char* label,int v[2],float v_speed,int v_min,int v_max,const char* format);
    bool (* igDragInt3) (const char* label,int v[3],float v_speed,int v_min,int v_max,const char* format);
    bool (* igDragInt4) (const char* label,int v[4],float v_speed,int v_min,int v_max,const char* format);
    bool (* igDragIntRange2) (const char* label,int* v_current_min,int* v_current_max,float v_speed,int v_min,int v_max,const char* format,const char* format_max);
    bool (* igDragScalar) (const char* label,ImGuiDataType data_type,void* v,float v_speed,const void* v_min,const void* v_max,const char* format,float power);
    bool (* igDragScalarN) (const char* label,ImGuiDataType data_type,void* v,int components,float v_speed,const void* v_min,const void* v_max,const char* format,float power);
    bool (* igSliderFloat) (const char* label,float* v,float v_min,float v_max,const char* format,float power);
    bool (* igSliderFloat2) (const char* label,float v[2],float v_min,float v_max,const char* format,float power);
    bool (* igSliderFloat3) (const char* label,float v[3],float v_min,float v_max,const char* format,float power);
    bool (* igSliderFloat4) (const char* label,float v[4],float v_min,float v_max,const char* format,float power);
    bool (* igSliderAngle) (const char* label,float* v_rad,float v_degrees_min,float v_degrees_max,const char* format);
    bool (* igSliderInt) (const char* label,int* v,int v_min,int v_max,const char* format);
    bool (* igSliderInt2) (const char* label,int v[2],int v_min,int v_max,const char* format);
    bool (* igSliderInt3) (const char* label,int v[3],int v_min,int v_max,const char* format);
    bool (* igSliderInt4) (const char* label,int v[4],int v_min,int v_max,const char* format);
    bool (* igSliderScalar) (const char* label,ImGuiDataType data_type,void* v,const void* v_min,const void* v_max,const char* format,float power);
    bool (* igSliderScalarN) (const char* label,ImGuiDataType data_type,void* v,int components,const void* v_min,const void* v_max,const char* format,float power);
    bool (* igVSliderFloat) (const char* label,const ImVec2 size,float* v,float v_min,float v_max,const char* format,float power);
    bool (* igVSliderInt) (const char* label,const ImVec2 size,int* v,int v_min,int v_max,const char* format);
    bool (* igVSliderScalar) (const char* label,const ImVec2 size,ImGuiDataType data_type,void* v,const void* v_min,const void* v_max,const char* format,float power);
    bool (* igInputText) (const char* label,char* buf,size_t buf_size,ImGuiInputTextFlags flags,ImGuiInputTextCallback callback,void* user_data);
    bool (* igInputTextMultiline) (const char* label,char* buf,size_t buf_size,const ImVec2 size,ImGuiInputTextFlags flags,ImGuiInputTextCallback callback,void* user_data);
    bool (* igInputTextWithHint) (const char* label,const char* hint,char* buf,size_t buf_size,ImGuiInputTextFlags flags,ImGuiInputTextCallback callback,void* user_data);
    bool (* igInputFloat) (const char* label,float* v,float step,float step_fast,const char* format,ImGuiInputTextFlags flags);
    bool (* igInputFloat2) (const char* label,float v[2],const char* format,ImGuiInputTextFlags flags);
    bool (* igInputFloat3) (const char* label,float v[3],const char* format,ImGuiInputTextFlags flags);
    bool (* igInputFloat4) (const char* label,float v[4],const char* format,ImGuiInputTextFlags flags);
    bool (* igInputInt) (const char* label,int* v,int step,int step_fast,ImGuiInputTextFlags flags);
    bool (* igInputInt2) (const char* label,int v[2],ImGuiInputTextFlags flags);
    bool (* igInputInt3) (const char* label,int v[3],ImGuiInputTextFlags flags);
    bool (* igInputInt4) (const char* label,int v[4],ImGuiInputTextFlags flags);
    bool (* igInputDouble) (const char* label,double* v,double step,double step_fast,const char* format,ImGuiInputTextFlags flags);
    bool (* igInputScalar) (const char* label,ImGuiDataType data_type,void* v,const void* step,const void* step_fast,const char* format,ImGuiInputTextFlags flags);
    bool (* igInputScalarN) (const char* label,ImGuiDataType data_type,void* v,int components,const void* step,const void* step_fast,const char* format,ImGuiInputTextFlags flags);
    bool (* igColorEdit3) (const char* label,float col[3],ImGuiColorEditFlags flags);
    bool (* igColorEdit4) (const char* label,float col[4],ImGuiColorEditFlags flags);
    bool (* igColorPicker3) (const char* label,float col[3],ImGuiColorEditFlags flags);
    bool (* igColorPicker4) (const char* label,float col[4],ImGuiColorEditFlags flags,const float* ref_col);
    bool (* igColorButton) (const char* desc_id,const ImVec4 col,ImGuiColorEditFlags flags,ImVec2 size);
    void (* igSetColorEditOptions) (ImGuiColorEditFlags flags);
    bool (* igTreeNodeStr) (const char* label);
    bool (* igTreeNodeStrStr) (const char* str_id,const char* fmt,...);
    bool (* igTreeNodePtr) (const void* ptr_id,const char* fmt,...);
    bool (* igTreeNodeVStr) (const char* str_id,const char* fmt,va_list args);
    bool (* igTreeNodeVPtr) (const void* ptr_id,const char* fmt,va_list args);
    bool (* igTreeNodeExStr) (const char* label,ImGuiTreeNodeFlags flags);
    bool (* igTreeNodeExStrStr) (const char* str_id,ImGuiTreeNodeFlags flags,const char* fmt,...);
    bool (* igTreeNodeExPtr) (const void* ptr_id,ImGuiTreeNodeFlags flags,const char* fmt,...);
    bool (* igTreeNodeExVStr) (const char* str_id,ImGuiTreeNodeFlags flags,const char* fmt,va_list args);
    bool (* igTreeNodeExVPtr) (const void* ptr_id,ImGuiTreeNodeFlags flags,const char* fmt,va_list args);
    void (* igTreePushStr) (const char* str_id);
    void (* igTreePushPtr) (const void* ptr_id);
    void (* igTreePop) (void);
    void (* igTreeAdvanceToLabelPos) (void);
    float (* igGetTreeNodeToLabelSpacing) (void);
    void (* igSetNextTreeNodeOpen) (bool is_open,ImGuiCond cond);
    bool (* igCollapsingHeader) (const char* label,ImGuiTreeNodeFlags flags);
    bool (* igCollapsingHeaderBoolPtr) (const char* label,bool* p_open,ImGuiTreeNodeFlags flags);
    bool (* igSelectable) (const char* label,bool selected,ImGuiSelectableFlags flags,const ImVec2 size);
    bool (* igSelectableBoolPtr) (const char* label,bool* p_selected,ImGuiSelectableFlags flags,const ImVec2 size);
    bool (* igListBoxStr_arr) (const char* label,int* current_item,const char* const items[],int items_count,int height_in_items);
    bool (* igListBoxFnPtr) (const char* label,int* current_item,bool(*items_getter)(void* data,int idx,const char** out_text),void* data,int items_count,int height_in_items);
    bool (* igListBoxHeaderVec2) (const char* label,const ImVec2 size);
    bool (* igListBoxHeaderInt) (const char* label,int items_count,int height_in_items);
    void (* igListBoxFooter) (void);
    void (* igPlotLines) (const char* label,const float* values,int values_count,int values_offset,const char* overlay_text,float scale_min,float scale_max,ImVec2 graph_size,int stride);
    void (* igPlotLinesFnPtr) (const char* label,float(*values_getter)(void* data,int idx),void* data,int values_count,int values_offset,const char* overlay_text,float scale_min,float scale_max,ImVec2 graph_size);
    void (* igPlotHistogramFloatPtr) (const char* label,const float* values,int values_count,int values_offset,const char* overlay_text,float scale_min,float scale_max,ImVec2 graph_size,int stride);
    void (* igPlotHistogramFnPtr) (const char* label,float(*values_getter)(void* data,int idx),void* data,int values_count,int values_offset,const char* overlay_text,float scale_min,float scale_max,ImVec2 graph_size);
    void (* igValueBool) (const char* prefix,bool b);
    void (* igValueInt) (const char* prefix,int v);
    void (* igValueUint) (const char* prefix,unsigned int v);
    void (* igValueFloat) (const char* prefix,float v,const char* float_format);
    bool (* igBeginMainMenuBar) (void);
    void (* igEndMainMenuBar) (void);
    bool (* igBeginMenuBar) (void);
    void (* igEndMenuBar) (void);
    bool (* igBeginMenu) (const char* label,bool enabled);
    void (* igEndMenu) (void);
    bool (* igMenuItemBool) (const char* label,const char* shortcut,bool selected,bool enabled);
    bool (* igMenuItemBoolPtr) (const char* label,const char* shortcut,bool* p_selected,bool enabled);
    void (* igBeginTooltip) (void);
    void (* igEndTooltip) (void);
    void (* igSetTooltip) (const char* fmt,...);
    void (* igSetTooltipV) (const char* fmt,va_list args);
    void (* igOpenPopup) (const char* str_id);
    bool (* igBeginPopup) (const char* str_id,ImGuiWindowFlags flags);
    bool (* igBeginPopupContextItem) (const char* str_id,int mouse_button);
    bool (* igBeginPopupContextWindow) (const char* str_id,int mouse_button,bool also_over_items);
    bool (* igBeginPopupContextVoid) (const char* str_id,int mouse_button);
    bool (* igBeginPopupModal) (const char* name,bool* p_open,ImGuiWindowFlags flags);
    void (* igEndPopup) (void);
    bool (* igOpenPopupOnItemClick) (const char* str_id,int mouse_button);
    bool (* igIsPopupOpen) (const char* str_id);
    void (* igCloseCurrentPopup) (void);
    void (* igColumns) (int count,const char* id,bool border);
    void (* igNextColumn) (void);
    int (* igGetColumnIndex) (void);
    float (* igGetColumnWidth) (int column_index);
    void (* igSetColumnWidth) (int column_index,float width);
    float (* igGetColumnOffset) (int column_index);
    void (* igSetColumnOffset) (int column_index,float offset_x);
    int (* igGetColumnsCount) (void);
    bool (* igBeginTabBar) (const char* str_id,ImGuiTabBarFlags flags);
    void (* igEndTabBar) (void);
    bool (* igBeginTabItem) (const char* label,bool* p_open,ImGuiTabItemFlags flags);
    void (* igEndTabItem) (void);
    void (* igSetTabItemClosed) (const char* tab_or_docked_window_label);
    void (* igLogToTTY) (int auto_open_depth);
    void (* igLogToFile) (int auto_open_depth,const char* filename);
    void (* igLogToClipboard) (int auto_open_depth);
    void (* igLogFinish) (void);
    void (* igLogButtons) (void);
    bool (* igBeginDragDropSource) (ImGuiDragDropFlags flags);
    bool (* igSetDragDropPayload) (const char* type,const void* data,size_t sz,ImGuiCond cond);
    void (* igEndDragDropSource) (void);
    bool (* igBeginDragDropTarget) (void);
    const ImGuiPayload* (* igAcceptDragDropPayload) (const char* type,ImGuiDragDropFlags flags);
    void (* igEndDragDropTarget) (void);
    const ImGuiPayload* (* igGetDragDropPayload) (void);
    void (* igPushClipRect) (const ImVec2 clip_rect_min,const ImVec2 clip_rect_max,bool intersect_with_current_clip_rect);
    void (* igPopClipRect) (void);
    void (* igSetItemDefaultFocus) (void);
    void (* igSetKeyboardFocusHere) (int offset);
    bool (* igIsItemHovered) (ImGuiHoveredFlags flags);
    bool (* igIsItemActive) (void);
    bool (* igIsItemFocused) (void);
    bool (* igIsItemClicked) (int mouse_button);
    bool (* igIsItemVisible) (void);
    bool (* igIsItemEdited) (void);
    bool (* igIsItemActivated) (void);
    bool (* igIsItemDeactivated) (void);
    bool (* igIsItemDeactivatedAfterEdit) (void);
    bool (* igIsAnyItemHovered) (void);
    bool (* igIsAnyItemActive) (void);
    bool (* igIsAnyItemFocused) (void);
    ImVec2 (* igGetItemRectMin) (void);
    ImVec2 (* igGetItemRectMax) (void);
    ImVec2 (* igGetItemRectSize) (void);
    void (* igSetItemAllowOverlap) (void);
    bool (* igIsRectVisible) (const ImVec2 size);
    bool (* igIsRectVisibleVec2) (const ImVec2 rect_min,const ImVec2 rect_max);
    double (* igGetTime) (void);
    int (* igGetFrameCount) (void);
    ImDrawList* (* igGetBackgroundDrawList) (void);
    ImDrawList* (* igGetForegroundDrawList) (void);
    ImDrawListSharedData* (* igGetDrawListSharedData) (void);
    const char* (* igGetStyleColorName) (ImGuiCol idx);
    void (* igSetStateStorage) (ImGuiStorage* storage);
    ImGuiStorage* (* igGetStateStorage) (void);
    ImVec2 (* igCalcTextSize) (const char* text,const char* text_end,bool hide_text_after_double_hash,float wrap_width);
    void (* igCalcListClipping) (int items_count,float items_height,int* out_items_display_start,int* out_items_display_end);
    bool (* igBeginChildFrame) (ImGuiID id,const ImVec2 size,ImGuiWindowFlags flags);
    void (* igEndChildFrame) (void);
    ImVec4 (* igColorConvertU32ToFloat4) (ImU32 in);
    ImU32 (* igColorConvertFloat4ToU32) (const ImVec4 in);
    int (* igGetKeyIndex) (ImGuiKey imgui_key);
    bool (* igIsKeyDown) (int user_key_index);
    bool (* igIsKeyPressed) (int user_key_index,bool repeat);
    bool (* igIsKeyReleased) (int user_key_index);
    int (* igGetKeyPressedAmount) (int key_index,float repeat_delay,float rate);
    bool (* igIsMouseDown) (int button);
    bool (* igIsAnyMouseDown) (void);
    bool (* igIsMouseClicked) (int button,bool repeat);
    bool (* igIsMouseDoubleClicked) (int button);
    bool (* igIsMouseReleased) (int button);
    bool (* igIsMouseDragging) (int button,float lock_threshold);
    bool (* igIsMouseHoveringRect) (const ImVec2 r_min,const ImVec2 r_max,bool clip);
    bool (* igIsMousePosValid) (const ImVec2* mouse_pos);
    ImVec2 (* igGetMousePos) (void);
    ImVec2 (* igGetMousePosOnOpeningCurrentPopup) (void);
    ImVec2 (* igGetMouseDragDelta) (int button,float lock_threshold);
    void (* igResetMouseDragDelta) (int button);
    ImGuiMouseCursor (* igGetMouseCursor) (void);
    void (* igSetMouseCursor) (ImGuiMouseCursor type);
    void (* igCaptureKeyboardFromApp) (bool want_capture_keyboard_value);
    void (* igCaptureMouseFromApp) (bool want_capture_mouse_value);
    const char* (* igGetClipboardText) (void);
    void (* igSetClipboardText) (const char* text);
    void (* igLoadIniSettingsFromDisk) (const char* ini_filename);
    void (* igLoadIniSettingsFromMemory) (const char* ini_data,size_t ini_size);
    void (* igSaveIniSettingsToDisk) (const char* ini_filename);
    const char* (* igSaveIniSettingsToMemory) (size_t* out_ini_size);
    void (* igSetAllocatorFunctions) (void*(*alloc_func)(size_t sz,void* user_data),void(*free_func)(void* ptr,void* user_data),void* user_data);
    void* (* igMemAlloc) (size_t size);
    void (* igMemFree) (void* ptr);
    ImGuiStyle* (* ImGuiStyle_ImGuiStyle) (void);
    void (* ImGuiStyle_destroy) (ImGuiStyle* self);
    void (* ImGuiStyle_ScaleAllSizes) (ImGuiStyle* self,float scale_factor);
    void (* ImGuiIO_AddInputCharacter) (ImGuiIO* self,ImWchar c);
    void (* ImGuiIO_AddInputCharactersUTF8) (ImGuiIO* self,const char* str);
    void (* ImGuiIO_ClearInputCharacters) (ImGuiIO* self);
    ImGuiIO* (* ImGuiIO_ImGuiIO) (void);
    void (* ImGuiIO_destroy) (ImGuiIO* self);
    ImGuiInputTextCallbackData* (* ImGuiInputTextCallbackData_ImGuiInputTextCallbackData) (void);
    void (* ImGuiInputTextCallbackData_destroy) (ImGuiInputTextCallbackData* self);
    void (* ImGuiInputTextCallbackData_DeleteChars) (ImGuiInputTextCallbackData* self,int pos,int bytes_count);
    void (* ImGuiInputTextCallbackData_InsertChars) (ImGuiInputTextCallbackData* self,int pos,const char* text,const char* text_end);
    bool (* ImGuiInputTextCallbackData_HasSelection) (ImGuiInputTextCallbackData* self);
    ImGuiPayload* (* ImGuiPayload_ImGuiPayload) (void);
    void (* ImGuiPayload_destroy) (ImGuiPayload* self);
    void (* ImGuiPayload_Clear) (ImGuiPayload* self);
    bool (* ImGuiPayload_IsDataType) (ImGuiPayload* self,const char* type);
    bool (* ImGuiPayload_IsPreview) (ImGuiPayload* self);
    bool (* ImGuiPayload_IsDelivery) (ImGuiPayload* self);
    ImGuiOnceUponAFrame* (* ImGuiOnceUponAFrame_ImGuiOnceUponAFrame) (void);
    void (* ImGuiOnceUponAFrame_destroy) (ImGuiOnceUponAFrame* self);
    ImGuiTextFilter* (* ImGuiTextFilter_ImGuiTextFilter) (const char* default_filter);
    void (* ImGuiTextFilter_destroy) (ImGuiTextFilter* self);
    bool (* ImGuiTextFilter_Draw) (ImGuiTextFilter* self,const char* label,float width);
    bool (* ImGuiTextFilter_PassFilter) (ImGuiTextFilter* self,const char* text,const char* text_end);
    void (* ImGuiTextFilter_Build) (ImGuiTextFilter* self);
    void (* ImGuiTextFilter_Clear) (ImGuiTextFilter* self);
    bool (* ImGuiTextFilter_IsActive) (ImGuiTextFilter* self);
    TextRange* (* TextRange_TextRange) (void);
    void (* TextRange_destroy) (TextRange* self);
    TextRange* (* TextRange_TextRangeStr) (const char* _b,const char* _e);
    const char* (* TextRange_begin) (TextRange* self);
    const char* (* TextRange_end) (TextRange* self);
    bool (* TextRange_empty) (TextRange* self);
    void (* TextRange_split) (TextRange* self,char separator,ImVector_TextRange* out);
    ImGuiTextBuffer* (* ImGuiTextBuffer_ImGuiTextBuffer) (void);
    void (* ImGuiTextBuffer_destroy) (ImGuiTextBuffer* self);
    const char* (* ImGuiTextBuffer_begin) (ImGuiTextBuffer* self);
    const char* (* ImGuiTextBuffer_end) (ImGuiTextBuffer* self);
    int (* ImGuiTextBuffer_size) (ImGuiTextBuffer* self);
    bool (* ImGuiTextBuffer_empty) (ImGuiTextBuffer* self);
    void (* ImGuiTextBuffer_clear) (ImGuiTextBuffer* self);
    void (* ImGuiTextBuffer_reserve) (ImGuiTextBuffer* self,int capacity);
    const char* (* ImGuiTextBuffer_c_str) (ImGuiTextBuffer* self);
    void (* ImGuiTextBuffer_append) (ImGuiTextBuffer* self,const char* str,const char* str_end);
    void (* ImGuiTextBuffer_appendfv) (ImGuiTextBuffer* self,const char* fmt,va_list args);
    Pair* (* Pair_PairInt) (ImGuiID _key,int _val_i);
    void (* Pair_destroy) (Pair* self);
    Pair* (* Pair_PairFloat) (ImGuiID _key,float _val_f);
    Pair* (* Pair_PairPtr) (ImGuiID _key,void* _val_p);
    void (* ImGuiStorage_Clear) (ImGuiStorage* self);
    int (* ImGuiStorage_GetInt) (ImGuiStorage* self,ImGuiID key,int default_val);
    void (* ImGuiStorage_SetInt) (ImGuiStorage* self,ImGuiID key,int val);
    bool (* ImGuiStorage_GetBool) (ImGuiStorage* self,ImGuiID key,bool default_val);
    void (* ImGuiStorage_SetBool) (ImGuiStorage* self,ImGuiID key,bool val);
    float (* ImGuiStorage_GetFloat) (ImGuiStorage* self,ImGuiID key,float default_val);
    void (* ImGuiStorage_SetFloat) (ImGuiStorage* self,ImGuiID key,float val);
    void* (* ImGuiStorage_GetVoidPtr) (ImGuiStorage* self,ImGuiID key);
    void (* ImGuiStorage_SetVoidPtr) (ImGuiStorage* self,ImGuiID key,void* val);
    int* (* ImGuiStorage_GetIntRef) (ImGuiStorage* self,ImGuiID key,int default_val);
    bool* (* ImGuiStorage_GetBoolRef) (ImGuiStorage* self,ImGuiID key,bool default_val);
    float* (* ImGuiStorage_GetFloatRef) (ImGuiStorage* self,ImGuiID key,float default_val);
    void** (* ImGuiStorage_GetVoidPtrRef) (ImGuiStorage* self,ImGuiID key,void* default_val);
    void (* ImGuiStorage_SetAllInt) (ImGuiStorage* self,int val);
    void (* ImGuiStorage_BuildSortByKey) (ImGuiStorage* self);
    ImGuiListClipper* (* ImGuiListClipper_ImGuiListClipper) (int items_count,float items_height);
    void (* ImGuiListClipper_destroy) (ImGuiListClipper* self);
    bool (* ImGuiListClipper_Step) (ImGuiListClipper* self);
    void (* ImGuiListClipper_Begin) (ImGuiListClipper* self,int items_count,float items_height);
    void (* ImGuiListClipper_End) (ImGuiListClipper* self);
    ImColor* (* ImColor_ImColor) (void);
    void (* ImColor_destroy) (ImColor* self);
    ImColor* (* ImColor_ImColorInt) (int r,int g,int b,int a);
    ImColor* (* ImColor_ImColorU32) (ImU32 rgba);
    ImColor* (* ImColor_ImColorFloat) (float r,float g,float b,float a);
    ImColor* (* ImColor_ImColorVec4) (const ImVec4 col);
    void (* ImColor_SetHSV) (ImColor* self,float h,float s,float v,float a);
    ImColor (* ImColor_HSV) (ImColor* self,float h,float s,float v,float a);
    ImDrawCmd* (* ImDrawCmd_ImDrawCmd) (void);
    void (* ImDrawCmd_destroy) (ImDrawCmd* self);
    ImDrawList* (* ImDrawList_ImDrawList) (const ImDrawListSharedData* shared_data);
    void (* ImDrawList_destroy) (ImDrawList* self);
    void (* ImDrawList_PushClipRect) (ImDrawList* self,ImVec2 clip_rect_min,ImVec2 clip_rect_max,bool intersect_with_current_clip_rect);
    void (* ImDrawList_PushClipRectFullScreen) (ImDrawList* self);
    void (* ImDrawList_PopClipRect) (ImDrawList* self);
    void (* ImDrawList_PushTextureID) (ImDrawList* self,ImTextureID texture_id);
    void (* ImDrawList_PopTextureID) (ImDrawList* self);
    ImVec2 (* ImDrawList_GetClipRectMin) (ImDrawList* self);
    ImVec2 (* ImDrawList_GetClipRectMax) (ImDrawList* self);
    void (* ImDrawList_AddLine) (ImDrawList* self,const ImVec2 a,const ImVec2 b,ImU32 col,float thickness);
    void (* ImDrawList_AddRect) (ImDrawList* self,const ImVec2 a,const ImVec2 b,ImU32 col,float rounding,int rounding_corners_flags,float thickness);
    void (* ImDrawList_AddRectFilled) (ImDrawList* self,const ImVec2 a,const ImVec2 b,ImU32 col,float rounding,int rounding_corners_flags);
    void (* ImDrawList_AddRectFilledMultiColor) (ImDrawList* self,const ImVec2 a,const ImVec2 b,ImU32 col_upr_left,ImU32 col_upr_right,ImU32 col_bot_right,ImU32 col_bot_left);
    void (* ImDrawList_AddQuad) (ImDrawList* self,const ImVec2 a,const ImVec2 b,const ImVec2 c,const ImVec2 d,ImU32 col,float thickness);
    void (* ImDrawList_AddQuadFilled) (ImDrawList* self,const ImVec2 a,const ImVec2 b,const ImVec2 c,const ImVec2 d,ImU32 col);
    void (* ImDrawList_AddTriangle) (ImDrawList* self,const ImVec2 a,const ImVec2 b,const ImVec2 c,ImU32 col,float thickness);
    void (* ImDrawList_AddTriangleFilled) (ImDrawList* self,const ImVec2 a,const ImVec2 b,const ImVec2 c,ImU32 col);
    void (* ImDrawList_AddCircle) (ImDrawList* self,const ImVec2 centre,float radius,ImU32 col,int num_segments,float thickness);
    void (* ImDrawList_AddCircleFilled) (ImDrawList* self,const ImVec2 centre,float radius,ImU32 col,int num_segments);
    void (* ImDrawList_AddText) (ImDrawList* self,const ImVec2 pos,ImU32 col,const char* text_begin,const char* text_end);
    void (* ImDrawList_AddTextFontPtr) (ImDrawList* self,const ImFont* font,float font_size,const ImVec2 pos,ImU32 col,const char* text_begin,const char* text_end,float wrap_width,const ImVec4* cpu_fine_clip_rect);
    void (* ImDrawList_AddImage) (ImDrawList* self,ImTextureID user_texture_id,const ImVec2 a,const ImVec2 b,const ImVec2 uv_a,const ImVec2 uv_b,ImU32 col);
    void (* ImDrawList_AddImageQuad) (ImDrawList* self,ImTextureID user_texture_id,const ImVec2 a,const ImVec2 b,const ImVec2 c,const ImVec2 d,const ImVec2 uv_a,const ImVec2 uv_b,const ImVec2 uv_c,const ImVec2 uv_d,ImU32 col);
    void (* ImDrawList_AddImageRounded) (ImDrawList* self,ImTextureID user_texture_id,const ImVec2 a,const ImVec2 b,const ImVec2 uv_a,const ImVec2 uv_b,ImU32 col,float rounding,int rounding_corners);
    void (* ImDrawList_AddPolyline) (ImDrawList* self,const ImVec2* points,int num_points,ImU32 col,bool closed,float thickness);
    void (* ImDrawList_AddConvexPolyFilled) (ImDrawList* self,const ImVec2* points,int num_points,ImU32 col);
    void (* ImDrawList_AddBezierCurve) (ImDrawList* self,const ImVec2 pos0,const ImVec2 cp0,const ImVec2 cp1,const ImVec2 pos1,ImU32 col,float thickness,int num_segments);
    void (* ImDrawList_PathClear) (ImDrawList* self);
    void (* ImDrawList_PathLineTo) (ImDrawList* self,const ImVec2 pos);
    void (* ImDrawList_PathLineToMergeDuplicate) (ImDrawList* self,const ImVec2 pos);
    void (* ImDrawList_PathFillConvex) (ImDrawList* self,ImU32 col);
    void (* ImDrawList_PathStroke) (ImDrawList* self,ImU32 col,bool closed,float thickness);
    void (* ImDrawList_PathArcTo) (ImDrawList* self,const ImVec2 centre,float radius,float a_min,float a_max,int num_segments);
    void (* ImDrawList_PathArcToFast) (ImDrawList* self,const ImVec2 centre,float radius,int a_min_of_12,int a_max_of_12);
    void (* ImDrawList_PathBezierCurveTo) (ImDrawList* self,const ImVec2 p1,const ImVec2 p2,const ImVec2 p3,int num_segments);
    void (* ImDrawList_PathRect) (ImDrawList* self,const ImVec2 rect_min,const ImVec2 rect_max,float rounding,int rounding_corners_flags);
    void (* ImDrawList_ChannelsSplit) (ImDrawList* self,int channels_count);
    void (* ImDrawList_ChannelsMerge) (ImDrawList* self);
    void (* ImDrawList_ChannelsSetCurrent) (ImDrawList* self,int channel_index);
    void (* ImDrawList_AddCallback) (ImDrawList* self,ImDrawCallback callback,void* callback_data);
    void (* ImDrawList_AddDrawCmd) (ImDrawList* self);
    ImDrawList* (* ImDrawList_CloneOutput) (ImDrawList* self);
    void (* ImDrawList_Clear) (ImDrawList* self);
    void (* ImDrawList_ClearFreeMemory) (ImDrawList* self);
    void (* ImDrawList_PrimReserve) (ImDrawList* self,int idx_count,int vtx_count);
    void (* ImDrawList_PrimRect) (ImDrawList* self,const ImVec2 a,const ImVec2 b,ImU32 col);
    void (* ImDrawList_PrimRectUV) (ImDrawList* self,const ImVec2 a,const ImVec2 b,const ImVec2 uv_a,const ImVec2 uv_b,ImU32 col);
    void (* ImDrawList_PrimQuadUV) (ImDrawList* self,const ImVec2 a,const ImVec2 b,const ImVec2 c,const ImVec2 d,const ImVec2 uv_a,const ImVec2 uv_b,const ImVec2 uv_c,const ImVec2 uv_d,ImU32 col);
    void (* ImDrawList_PrimWriteVtx) (ImDrawList* self,const ImVec2 pos,const ImVec2 uv,ImU32 col);
    void (* ImDrawList_PrimWriteIdx) (ImDrawList* self,ImDrawIdx idx);
    void (* ImDrawList_PrimVtx) (ImDrawList* self,const ImVec2 pos,const ImVec2 uv,ImU32 col);
    void (* ImDrawList_UpdateClipRect) (ImDrawList* self);
    void (* ImDrawList_UpdateTextureID) (ImDrawList* self);
    ImDrawData* (* ImDrawData_ImDrawData) (void);
    void (* ImDrawData_destroy) (ImDrawData* self);
    void (* ImDrawData_Clear) (ImDrawData* self);
    void (* ImDrawData_DeIndexAllBuffers) (ImDrawData* self);
    void (* ImDrawData_ScaleClipRects) (ImDrawData* self,const ImVec2 fb_scale);
    ImFontConfig* (* ImFontConfig_ImFontConfig) (void);
    void (* ImFontConfig_destroy) (ImFontConfig* self);
    ImFontGlyphRangesBuilder* (* ImFontGlyphRangesBuilder_ImFontGlyphRangesBuilder) (void);
    void (* ImFontGlyphRangesBuilder_destroy) (ImFontGlyphRangesBuilder* self);
    bool (* ImFontGlyphRangesBuilder_GetBit) (ImFontGlyphRangesBuilder* self,int n);
    void (* ImFontGlyphRangesBuilder_SetBit) (ImFontGlyphRangesBuilder* self,int n);
    void (* ImFontGlyphRangesBuilder_AddChar) (ImFontGlyphRangesBuilder* self,ImWchar c);
    void (* ImFontGlyphRangesBuilder_AddText) (ImFontGlyphRangesBuilder* self,const char* text,const char* text_end);
    void (* ImFontGlyphRangesBuilder_AddRanges) (ImFontGlyphRangesBuilder* self,const ImWchar* ranges);
    void (* ImFontGlyphRangesBuilder_BuildRanges) (ImFontGlyphRangesBuilder* self,ImVector_ImWchar* out_ranges);
    ImFontAtlas* (* ImFontAtlas_ImFontAtlas) (void);
    void (* ImFontAtlas_destroy) (ImFontAtlas* self);
    ImFont* (* ImFontAtlas_AddFont) (ImFontAtlas* self,const ImFontConfig* font_cfg);
    ImFont* (* ImFontAtlas_AddFontDefault) (ImFontAtlas* self,const ImFontConfig* font_cfg);
    ImFont* (* ImFontAtlas_AddFontFromFileTTF) (ImFontAtlas* self,const char* filename,float size_pixels,const ImFontConfig* font_cfg,const ImWchar* glyph_ranges);
    ImFont* (* ImFontAtlas_AddFontFromMemoryTTF) (ImFontAtlas* self,void* font_data,int font_size,float size_pixels,const ImFontConfig* font_cfg,const ImWchar* glyph_ranges);
    ImFont* (* ImFontAtlas_AddFontFromMemoryCompressedTTF) (ImFontAtlas* self,const void* compressed_font_data,int compressed_font_size,float size_pixels,const ImFontConfig* font_cfg,const ImWchar* glyph_ranges);
    ImFont* (* ImFontAtlas_AddFontFromMemoryCompressedBase85TTF) (ImFontAtlas* self,const char* compressed_font_data_base85,float size_pixels,const ImFontConfig* font_cfg,const ImWchar* glyph_ranges);
    void (* ImFontAtlas_ClearInputData) (ImFontAtlas* self);
    void (* ImFontAtlas_ClearTexData) (ImFontAtlas* self);
    void (* ImFontAtlas_ClearFonts) (ImFontAtlas* self);
    void (* ImFontAtlas_Clear) (ImFontAtlas* self);
    bool (* ImFontAtlas_Build) (ImFontAtlas* self);
    void (* ImFontAtlas_GetTexDataAsAlpha8) (ImFontAtlas* self,unsigned char** out_pixels,int* out_width,int* out_height,int* out_bytes_per_pixel);
    void (* ImFontAtlas_GetTexDataAsRGBA32) (ImFontAtlas* self,unsigned char** out_pixels,int* out_width,int* out_height,int* out_bytes_per_pixel);
    bool (* ImFontAtlas_IsBuilt) (ImFontAtlas* self);
    void (* ImFontAtlas_SetTexID) (ImFontAtlas* self,ImTextureID id);
    const ImWchar* (* ImFontAtlas_GetGlyphRangesDefault) (ImFontAtlas* self);
    const ImWchar* (* ImFontAtlas_GetGlyphRangesKorean) (ImFontAtlas* self);
    const ImWchar* (* ImFontAtlas_GetGlyphRangesJapanese) (ImFontAtlas* self);
    const ImWchar* (* ImFontAtlas_GetGlyphRangesChineseFull) (ImFontAtlas* self);
    const ImWchar* (* ImFontAtlas_GetGlyphRangesChineseSimplifiedCommon) (ImFontAtlas* self);
    const ImWchar* (* ImFontAtlas_GetGlyphRangesCyrillic) (ImFontAtlas* self);
    const ImWchar* (* ImFontAtlas_GetGlyphRangesThai) (ImFontAtlas* self);
    const ImWchar* (* ImFontAtlas_GetGlyphRangesVietnamese) (ImFontAtlas* self);
    CustomRect* (* CustomRect_CustomRect) (void);
    void (* CustomRect_destroy) (CustomRect* self);
    bool (* CustomRect_IsPacked) (CustomRect* self);
    int (* ImFontAtlas_AddCustomRectRegular) (ImFontAtlas* self,unsigned int id,int width,int height);
    int (* ImFontAtlas_AddCustomRectFontGlyph) (ImFontAtlas* self,ImFont* font,ImWchar id,int width,int height,float advance_x,const ImVec2 offset);
    const CustomRect* (* ImFontAtlas_GetCustomRectByIndex) (ImFontAtlas* self,int index);
    void (* ImFontAtlas_CalcCustomRectUV) (ImFontAtlas* self,const CustomRect* rect,ImVec2* out_uv_min,ImVec2* out_uv_max);
    bool (* ImFontAtlas_GetMouseCursorTexData) (ImFontAtlas* self,ImGuiMouseCursor cursor,ImVec2* out_offset,ImVec2* out_size,ImVec2 out_uv_border[2],ImVec2 out_uv_fill[2]);
    ImFont* (* ImFont_ImFont) (void);
    void (* ImFont_destroy) (ImFont* self);
    const ImFontGlyph* (* ImFont_FindGlyph) (ImFont* self,ImWchar c);
    const ImFontGlyph* (* ImFont_FindGlyphNoFallback) (ImFont* self,ImWchar c);
    float (* ImFont_GetCharAdvance) (ImFont* self,ImWchar c);
    bool (* ImFont_IsLoaded) (ImFont* self);
    const char* (* ImFont_GetDebugName) (ImFont* self);
    ImVec2 (* ImFont_CalcTextSizeA) (ImFont* self,float size,float max_width,float wrap_width,const char* text_begin,const char* text_end,const char** remaining);
    const char* (* ImFont_CalcWordWrapPositionA) (ImFont* self,float scale,const char* text,const char* text_end,float wrap_width);
    void (* ImFont_RenderChar) (ImFont* self,ImDrawList* draw_list,float size,ImVec2 pos,ImU32 col,ImWchar c);
    void (* ImFont_RenderText) (ImFont* self,ImDrawList* draw_list,float size,ImVec2 pos,ImU32 col,const ImVec4 clip_rect,const char* text_begin,const char* text_end,float wrap_width,bool cpu_fine_clip);
    void (* ImFont_BuildLookupTable) (ImFont* self);
    void (* ImFont_ClearOutputData) (ImFont* self);
    void (* ImFont_GrowIndex) (ImFont* self,int new_size);
    void (* ImFont_AddGlyph) (ImFont* self,ImWchar c,float x0,float y0,float x1,float y1,float u0,float v0,float u1,float v1,float advance_x);
    void (* ImFont_AddRemapChar) (ImFont* self,ImWchar dst,ImWchar src,bool overwrite_dst);
    void (* ImFont_SetFallbackChar) (ImFont* self,ImWchar c);
    void (* igGetWindowPos_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetWindowPos_nonUDT2) (void);
    void (* igGetWindowSize_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetWindowSize_nonUDT2) (void);
    void (* igGetContentRegionMax_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetContentRegionMax_nonUDT2) (void);
    void (* igGetContentRegionAvail_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetContentRegionAvail_nonUDT2) (void);
    void (* igGetWindowContentRegionMin_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetWindowContentRegionMin_nonUDT2) (void);
    void (* igGetWindowContentRegionMax_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetWindowContentRegionMax_nonUDT2) (void);
    void (* igGetFontTexUvWhitePixel_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetFontTexUvWhitePixel_nonUDT2) (void);
    void (* igGetCursorPos_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetCursorPos_nonUDT2) (void);
    void (* igGetCursorStartPos_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetCursorStartPos_nonUDT2) (void);
    void (* igGetCursorScreenPos_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetCursorScreenPos_nonUDT2) (void);
    void (* igGetItemRectMin_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetItemRectMin_nonUDT2) (void);
    void (* igGetItemRectMax_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetItemRectMax_nonUDT2) (void);
    void (* igGetItemRectSize_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetItemRectSize_nonUDT2) (void);
    void (* igCalcTextSize_nonUDT) (ImVec2 *pOut,const char* text,const char* text_end,bool hide_text_after_double_hash,float wrap_width);
    ImVec2_Simple (* igCalcTextSize_nonUDT2) (const char* text,const char* text_end,bool hide_text_after_double_hash,float wrap_width);
    void (* igColorConvertU32ToFloat4_nonUDT) (ImVec4 *pOut,ImU32 in);
    ImVec4_Simple (* igColorConvertU32ToFloat4_nonUDT2) (ImU32 in);
    void (* igGetMousePos_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetMousePos_nonUDT2) (void);
    void (* igGetMousePosOnOpeningCurrentPopup_nonUDT) (ImVec2 *pOut);
    ImVec2_Simple (* igGetMousePosOnOpeningCurrentPopup_nonUDT2) (void);
    void (* igGetMouseDragDelta_nonUDT) (ImVec2 *pOut,int button,float lock_threshold);
    ImVec2_Simple (* igGetMouseDragDelta_nonUDT2) (int button,float lock_threshold);
    void (* ImColor_HSV_nonUDT) (ImColor *pOut,ImColor* self,float h,float s,float v,float a);
    ImColor_Simple (* ImColor_HSV_nonUDT2) (ImColor* self,float h,float s,float v,float a);
    void (* ImDrawList_GetClipRectMin_nonUDT) (ImVec2 *pOut,ImDrawList* self);
    ImVec2_Simple (* ImDrawList_GetClipRectMin_nonUDT2) (ImDrawList* self);
    void (* ImDrawList_GetClipRectMax_nonUDT) (ImVec2 *pOut,ImDrawList* self);
    ImVec2_Simple (* ImDrawList_GetClipRectMax_nonUDT2) (ImDrawList* self);
    void (* ImFont_CalcTextSizeA_nonUDT) (ImVec2 *pOut,ImFont* self,float size,float max_width,float wrap_width,const char* text_begin,const char* text_end,const char** remaining);
    ImVec2_Simple (* ImFont_CalcTextSizeA_nonUDT2) (ImFont* self,float size,float max_width,float wrap_width,const char* text_begin,const char* text_end,const char** remaining);
    ImVector_float* (* ImVector_float_ImVector_float) (void);
    void (* ImVector_float_destroy) (ImVector_float* self);
    ImVector_ImWchar* (* ImVector_ImWchar_ImVector_ImWchar) (void);
    void (* ImVector_ImWchar_destroy) (ImVector_ImWchar* self);
    ImVector_ImFontConfig* (* ImVector_ImFontConfig_ImVector_ImFontConfig) (void);
    void (* ImVector_ImFontConfig_destroy) (ImVector_ImFontConfig* self);
    ImVector_ImFontGlyph* (* ImVector_ImFontGlyph_ImVector_ImFontGlyph) (void);
    void (* ImVector_ImFontGlyph_destroy) (ImVector_ImFontGlyph* self);
    ImVector_TextRange* (* ImVector_TextRange_ImVector_TextRange) (void);
    void (* ImVector_TextRange_destroy) (ImVector_TextRange* self);
    ImVector_CustomRect* (* ImVector_CustomRect_ImVector_CustomRect) (void);
    void (* ImVector_CustomRect_destroy) (ImVector_CustomRect* self);
    ImVector_ImDrawChannel* (* ImVector_ImDrawChannel_ImVector_ImDrawChannel) (void);
    void (* ImVector_ImDrawChannel_destroy) (ImVector_ImDrawChannel* self);
    ImVector_char* (* ImVector_char_ImVector_char) (void);
    void (* ImVector_char_destroy) (ImVector_char* self);
    ImVector_ImTextureID* (* ImVector_ImTextureID_ImVector_ImTextureID) (void);
    void (* ImVector_ImTextureID_destroy) (ImVector_ImTextureID* self);
    ImVector_ImDrawVert* (* ImVector_ImDrawVert_ImVector_ImDrawVert) (void);
    void (* ImVector_ImDrawVert_destroy) (ImVector_ImDrawVert* self);
    ImVector_int* (* ImVector_int_ImVector_int) (void);
    void (* ImVector_int_destroy) (ImVector_int* self);
    ImVector_Pair* (* ImVector_Pair_ImVector_Pair) (void);
    void (* ImVector_Pair_destroy) (ImVector_Pair* self);
    ImVector_ImFontPtr* (* ImVector_ImFontPtr_ImVector_ImFontPtr) (void);
    void (* ImVector_ImFontPtr_destroy) (ImVector_ImFontPtr* self);
    ImVector_ImVec4* (* ImVector_ImVec4_ImVector_ImVec4) (void);
    void (* ImVector_ImVec4_destroy) (ImVector_ImVec4* self);
    ImVector_ImDrawCmd* (* ImVector_ImDrawCmd_ImVector_ImDrawCmd) (void);
    void (* ImVector_ImDrawCmd_destroy) (ImVector_ImDrawCmd* self);
    ImVector_ImDrawIdx* (* ImVector_ImDrawIdx_ImVector_ImDrawIdx) (void);
    void (* ImVector_ImDrawIdx_destroy) (ImVector_ImDrawIdx* self);
    ImVector_ImVec2* (* ImVector_ImVec2_ImVector_ImVec2) (void);
    void (* ImVector_ImVec2_destroy) (ImVector_ImVec2* self);
    ImVector_float* (* ImVector_float_ImVector_floatVector) (const ImVector_float src);
    ImVector_ImWchar* (* ImVector_ImWchar_ImVector_ImWcharVector) (const ImVector_ImWchar src);
    ImVector_ImFontConfig* (* ImVector_ImFontConfig_ImVector_ImFontConfigVector) (const ImVector_ImFontConfig src);
    ImVector_ImFontGlyph* (* ImVector_ImFontGlyph_ImVector_ImFontGlyphVector) (const ImVector_ImFontGlyph src);
    ImVector_TextRange* (* ImVector_TextRange_ImVector_TextRangeVector) (const ImVector_TextRange src);
    ImVector_CustomRect* (* ImVector_CustomRect_ImVector_CustomRectVector) (const ImVector_CustomRect src);
    ImVector_ImDrawChannel* (* ImVector_ImDrawChannel_ImVector_ImDrawChannelVector) (const ImVector_ImDrawChannel src);
    ImVector_char* (* ImVector_char_ImVector_charVector) (const ImVector_char src);
    ImVector_ImTextureID* (* ImVector_ImTextureID_ImVector_ImTextureIDVector) (const ImVector_ImTextureID src);
    ImVector_ImDrawVert* (* ImVector_ImDrawVert_ImVector_ImDrawVertVector) (const ImVector_ImDrawVert src);
    ImVector_int* (* ImVector_int_ImVector_intVector) (const ImVector_int src);
    ImVector_Pair* (* ImVector_Pair_ImVector_PairVector) (const ImVector_Pair src);
    ImVector_ImFontPtr* (* ImVector_ImFontPtr_ImVector_ImFontPtrVector) (const ImVector_ImFontPtr src);
    ImVector_ImVec4* (* ImVector_ImVec4_ImVector_ImVec4Vector) (const ImVector_ImVec4 src);
    ImVector_ImDrawCmd* (* ImVector_ImDrawCmd_ImVector_ImDrawCmdVector) (const ImVector_ImDrawCmd src);
    ImVector_ImDrawIdx* (* ImVector_ImDrawIdx_ImVector_ImDrawIdxVector) (const ImVector_ImDrawIdx src);
    ImVector_ImVec2* (* ImVector_ImVec2_ImVector_ImVec2Vector) (const ImVector_ImVec2 src);
    bool (* ImVector_float_empty) (const ImVector_float* self);
    bool (* ImVector_ImWchar_empty) (const ImVector_ImWchar* self);
    bool (* ImVector_ImFontConfig_empty) (const ImVector_ImFontConfig* self);
    bool (* ImVector_ImFontGlyph_empty) (const ImVector_ImFontGlyph* self);
    bool (* ImVector_TextRange_empty) (const ImVector_TextRange* self);
    bool (* ImVector_CustomRect_empty) (const ImVector_CustomRect* self);
    bool (* ImVector_ImDrawChannel_empty) (const ImVector_ImDrawChannel* self);
    bool (* ImVector_char_empty) (const ImVector_char* self);
    bool (* ImVector_ImTextureID_empty) (const ImVector_ImTextureID* self);
    bool (* ImVector_ImDrawVert_empty) (const ImVector_ImDrawVert* self);
    bool (* ImVector_int_empty) (const ImVector_int* self);
    bool (* ImVector_Pair_empty) (const ImVector_Pair* self);
    bool (* ImVector_ImFontPtr_empty) (const ImVector_ImFontPtr* self);
    bool (* ImVector_ImVec4_empty) (const ImVector_ImVec4* self);
    bool (* ImVector_ImDrawCmd_empty) (const ImVector_ImDrawCmd* self);
    bool (* ImVector_ImDrawIdx_empty) (const ImVector_ImDrawIdx* self);
    bool (* ImVector_ImVec2_empty) (const ImVector_ImVec2* self);
    int (* ImVector_float_size) (const ImVector_float* self);
    int (* ImVector_ImWchar_size) (const ImVector_ImWchar* self);
    int (* ImVector_ImFontConfig_size) (const ImVector_ImFontConfig* self);
    int (* ImVector_ImFontGlyph_size) (const ImVector_ImFontGlyph* self);
    int (* ImVector_TextRange_size) (const ImVector_TextRange* self);
    int (* ImVector_CustomRect_size) (const ImVector_CustomRect* self);
    int (* ImVector_ImDrawChannel_size) (const ImVector_ImDrawChannel* self);
    int (* ImVector_char_size) (const ImVector_char* self);
    int (* ImVector_ImTextureID_size) (const ImVector_ImTextureID* self);
    int (* ImVector_ImDrawVert_size) (const ImVector_ImDrawVert* self);
    int (* ImVector_int_size) (const ImVector_int* self);
    int (* ImVector_Pair_size) (const ImVector_Pair* self);
    int (* ImVector_ImFontPtr_size) (const ImVector_ImFontPtr* self);
    int (* ImVector_ImVec4_size) (const ImVector_ImVec4* self);
    int (* ImVector_ImDrawCmd_size) (const ImVector_ImDrawCmd* self);
    int (* ImVector_ImDrawIdx_size) (const ImVector_ImDrawIdx* self);
    int (* ImVector_ImVec2_size) (const ImVector_ImVec2* self);
    int (* ImVector_float_size_in_bytes) (const ImVector_float* self);
    int (* ImVector_ImWchar_size_in_bytes) (const ImVector_ImWchar* self);
    int (* ImVector_ImFontConfig_size_in_bytes) (const ImVector_ImFontConfig* self);
    int (* ImVector_ImFontGlyph_size_in_bytes) (const ImVector_ImFontGlyph* self);
    int (* ImVector_TextRange_size_in_bytes) (const ImVector_TextRange* self);
    int (* ImVector_CustomRect_size_in_bytes) (const ImVector_CustomRect* self);
    int (* ImVector_ImDrawChannel_size_in_bytes) (const ImVector_ImDrawChannel* self);
    int (* ImVector_char_size_in_bytes) (const ImVector_char* self);
    int (* ImVector_ImTextureID_size_in_bytes) (const ImVector_ImTextureID* self);
    int (* ImVector_ImDrawVert_size_in_bytes) (const ImVector_ImDrawVert* self);
    int (* ImVector_int_size_in_bytes) (const ImVector_int* self);
    int (* ImVector_Pair_size_in_bytes) (const ImVector_Pair* self);
    int (* ImVector_ImFontPtr_size_in_bytes) (const ImVector_ImFontPtr* self);
    int (* ImVector_ImVec4_size_in_bytes) (const ImVector_ImVec4* self);
    int (* ImVector_ImDrawCmd_size_in_bytes) (const ImVector_ImDrawCmd* self);
    int (* ImVector_ImDrawIdx_size_in_bytes) (const ImVector_ImDrawIdx* self);
    int (* ImVector_ImVec2_size_in_bytes) (const ImVector_ImVec2* self);
    int (* ImVector_float_capacity) (const ImVector_float* self);
    int (* ImVector_ImWchar_capacity) (const ImVector_ImWchar* self);
    int (* ImVector_ImFontConfig_capacity) (const ImVector_ImFontConfig* self);
    int (* ImVector_ImFontGlyph_capacity) (const ImVector_ImFontGlyph* self);
    int (* ImVector_TextRange_capacity) (const ImVector_TextRange* self);
    int (* ImVector_CustomRect_capacity) (const ImVector_CustomRect* self);
    int (* ImVector_ImDrawChannel_capacity) (const ImVector_ImDrawChannel* self);
    int (* ImVector_char_capacity) (const ImVector_char* self);
    int (* ImVector_ImTextureID_capacity) (const ImVector_ImTextureID* self);
    int (* ImVector_ImDrawVert_capacity) (const ImVector_ImDrawVert* self);
    int (* ImVector_int_capacity) (const ImVector_int* self);
    int (* ImVector_Pair_capacity) (const ImVector_Pair* self);
    int (* ImVector_ImFontPtr_capacity) (const ImVector_ImFontPtr* self);
    int (* ImVector_ImVec4_capacity) (const ImVector_ImVec4* self);
    int (* ImVector_ImDrawCmd_capacity) (const ImVector_ImDrawCmd* self);
    int (* ImVector_ImDrawIdx_capacity) (const ImVector_ImDrawIdx* self);
    int (* ImVector_ImVec2_capacity) (const ImVector_ImVec2* self);
    void (* ImVector_float_clear) (ImVector_float* self);
    void (* ImVector_ImWchar_clear) (ImVector_ImWchar* self);
    void (* ImVector_ImFontConfig_clear) (ImVector_ImFontConfig* self);
    void (* ImVector_ImFontGlyph_clear) (ImVector_ImFontGlyph* self);
    void (* ImVector_TextRange_clear) (ImVector_TextRange* self);
    void (* ImVector_CustomRect_clear) (ImVector_CustomRect* self);
    void (* ImVector_ImDrawChannel_clear) (ImVector_ImDrawChannel* self);
    void (* ImVector_char_clear) (ImVector_char* self);
    void (* ImVector_ImTextureID_clear) (ImVector_ImTextureID* self);
    void (* ImVector_ImDrawVert_clear) (ImVector_ImDrawVert* self);
    void (* ImVector_int_clear) (ImVector_int* self);
    void (* ImVector_Pair_clear) (ImVector_Pair* self);
    void (* ImVector_ImFontPtr_clear) (ImVector_ImFontPtr* self);
    void (* ImVector_ImVec4_clear) (ImVector_ImVec4* self);
    void (* ImVector_ImDrawCmd_clear) (ImVector_ImDrawCmd* self);
    void (* ImVector_ImDrawIdx_clear) (ImVector_ImDrawIdx* self);
    void (* ImVector_ImVec2_clear) (ImVector_ImVec2* self);
    float* (* ImVector_float_begin) (ImVector_float* self);
    ImWchar* (* ImVector_ImWchar_begin) (ImVector_ImWchar* self);
    ImFontConfig* (* ImVector_ImFontConfig_begin) (ImVector_ImFontConfig* self);
    ImFontGlyph* (* ImVector_ImFontGlyph_begin) (ImVector_ImFontGlyph* self);
    TextRange* (* ImVector_TextRange_begin) (ImVector_TextRange* self);
    CustomRect* (* ImVector_CustomRect_begin) (ImVector_CustomRect* self);
    ImDrawChannel* (* ImVector_ImDrawChannel_begin) (ImVector_ImDrawChannel* self);
    char* (* ImVector_char_begin) (ImVector_char* self);
    ImTextureID* (* ImVector_ImTextureID_begin) (ImVector_ImTextureID* self);
    ImDrawVert* (* ImVector_ImDrawVert_begin) (ImVector_ImDrawVert* self);
    int* (* ImVector_int_begin) (ImVector_int* self);
    Pair* (* ImVector_Pair_begin) (ImVector_Pair* self);
    ImFont** (* ImVector_ImFontPtr_begin) (ImVector_ImFontPtr* self);
    ImVec4* (* ImVector_ImVec4_begin) (ImVector_ImVec4* self);
    ImDrawCmd* (* ImVector_ImDrawCmd_begin) (ImVector_ImDrawCmd* self);
    ImDrawIdx* (* ImVector_ImDrawIdx_begin) (ImVector_ImDrawIdx* self);
    ImVec2* (* ImVector_ImVec2_begin) (ImVector_ImVec2* self);
    float const * (* ImVector_float_begin_const) (const ImVector_float* self);
    ImWchar const * (* ImVector_ImWchar_begin_const) (const ImVector_ImWchar* self);
    ImFontConfig const * (* ImVector_ImFontConfig_begin_const) (const ImVector_ImFontConfig* self);
    ImFontGlyph const * (* ImVector_ImFontGlyph_begin_const) (const ImVector_ImFontGlyph* self);
    TextRange const * (* ImVector_TextRange_begin_const) (const ImVector_TextRange* self);
    CustomRect const * (* ImVector_CustomRect_begin_const) (const ImVector_CustomRect* self);
    ImDrawChannel const * (* ImVector_ImDrawChannel_begin_const) (const ImVector_ImDrawChannel* self);
    char const * (* ImVector_char_begin_const) (const ImVector_char* self);
    ImTextureID const * (* ImVector_ImTextureID_begin_const) (const ImVector_ImTextureID* self);
    ImDrawVert const * (* ImVector_ImDrawVert_begin_const) (const ImVector_ImDrawVert* self);
    int const * (* ImVector_int_begin_const) (const ImVector_int* self);
    Pair const * (* ImVector_Pair_begin_const) (const ImVector_Pair* self);
    ImFont* const * (* ImVector_ImFontPtr_begin_const) (const ImVector_ImFontPtr* self);
    ImVec4 const * (* ImVector_ImVec4_begin_const) (const ImVector_ImVec4* self);
    ImDrawCmd const * (* ImVector_ImDrawCmd_begin_const) (const ImVector_ImDrawCmd* self);
    ImDrawIdx const * (* ImVector_ImDrawIdx_begin_const) (const ImVector_ImDrawIdx* self);
    ImVec2 const * (* ImVector_ImVec2_begin_const) (const ImVector_ImVec2* self);
    float* (* ImVector_float_end) (ImVector_float* self);
    ImWchar* (* ImVector_ImWchar_end) (ImVector_ImWchar* self);
    ImFontConfig* (* ImVector_ImFontConfig_end) (ImVector_ImFontConfig* self);
    ImFontGlyph* (* ImVector_ImFontGlyph_end) (ImVector_ImFontGlyph* self);
    TextRange* (* ImVector_TextRange_end) (ImVector_TextRange* self);
    CustomRect* (* ImVector_CustomRect_end) (ImVector_CustomRect* self);
    ImDrawChannel* (* ImVector_ImDrawChannel_end) (ImVector_ImDrawChannel* self);
    char* (* ImVector_char_end) (ImVector_char* self);
    ImTextureID* (* ImVector_ImTextureID_end) (ImVector_ImTextureID* self);
    ImDrawVert* (* ImVector_ImDrawVert_end) (ImVector_ImDrawVert* self);
    int* (* ImVector_int_end) (ImVector_int* self);
    Pair* (* ImVector_Pair_end) (ImVector_Pair* self);
    ImFont** (* ImVector_ImFontPtr_end) (ImVector_ImFontPtr* self);
    ImVec4* (* ImVector_ImVec4_end) (ImVector_ImVec4* self);
    ImDrawCmd* (* ImVector_ImDrawCmd_end) (ImVector_ImDrawCmd* self);
    ImDrawIdx* (* ImVector_ImDrawIdx_end) (ImVector_ImDrawIdx* self);
    ImVec2* (* ImVector_ImVec2_end) (ImVector_ImVec2* self);
    float const * (* ImVector_float_end_const) (const ImVector_float* self);
    ImWchar const * (* ImVector_ImWchar_end_const) (const ImVector_ImWchar* self);
    ImFontConfig const * (* ImVector_ImFontConfig_end_const) (const ImVector_ImFontConfig* self);
    ImFontGlyph const * (* ImVector_ImFontGlyph_end_const) (const ImVector_ImFontGlyph* self);
    TextRange const * (* ImVector_TextRange_end_const) (const ImVector_TextRange* self);
    CustomRect const * (* ImVector_CustomRect_end_const) (const ImVector_CustomRect* self);
    ImDrawChannel const * (* ImVector_ImDrawChannel_end_const) (const ImVector_ImDrawChannel* self);
    char const * (* ImVector_char_end_const) (const ImVector_char* self);
    ImTextureID const * (* ImVector_ImTextureID_end_const) (const ImVector_ImTextureID* self);
    ImDrawVert const * (* ImVector_ImDrawVert_end_const) (const ImVector_ImDrawVert* self);
    int const * (* ImVector_int_end_const) (const ImVector_int* self);
    Pair const * (* ImVector_Pair_end_const) (const ImVector_Pair* self);
    ImFont* const * (* ImVector_ImFontPtr_end_const) (const ImVector_ImFontPtr* self);
    ImVec4 const * (* ImVector_ImVec4_end_const) (const ImVector_ImVec4* self);
    ImDrawCmd const * (* ImVector_ImDrawCmd_end_const) (const ImVector_ImDrawCmd* self);
    ImDrawIdx const * (* ImVector_ImDrawIdx_end_const) (const ImVector_ImDrawIdx* self);
    ImVec2 const * (* ImVector_ImVec2_end_const) (const ImVector_ImVec2* self);
    float* (* ImVector_float_front) (ImVector_float* self);
    ImWchar* (* ImVector_ImWchar_front) (ImVector_ImWchar* self);
    ImFontConfig* (* ImVector_ImFontConfig_front) (ImVector_ImFontConfig* self);
    ImFontGlyph* (* ImVector_ImFontGlyph_front) (ImVector_ImFontGlyph* self);
    TextRange* (* ImVector_TextRange_front) (ImVector_TextRange* self);
    CustomRect* (* ImVector_CustomRect_front) (ImVector_CustomRect* self);
    ImDrawChannel* (* ImVector_ImDrawChannel_front) (ImVector_ImDrawChannel* self);
    char* (* ImVector_char_front) (ImVector_char* self);
    ImTextureID* (* ImVector_ImTextureID_front) (ImVector_ImTextureID* self);
    ImDrawVert* (* ImVector_ImDrawVert_front) (ImVector_ImDrawVert* self);
    int* (* ImVector_int_front) (ImVector_int* self);
    Pair* (* ImVector_Pair_front) (ImVector_Pair* self);
    ImFont** (* ImVector_ImFontPtr_front) (ImVector_ImFontPtr* self);
    ImVec4* (* ImVector_ImVec4_front) (ImVector_ImVec4* self);
    ImDrawCmd* (* ImVector_ImDrawCmd_front) (ImVector_ImDrawCmd* self);
    ImDrawIdx* (* ImVector_ImDrawIdx_front) (ImVector_ImDrawIdx* self);
    ImVec2* (* ImVector_ImVec2_front) (ImVector_ImVec2* self);
    float const * (* ImVector_float_front_const) (const ImVector_float* self);
    ImWchar const * (* ImVector_ImWchar_front_const) (const ImVector_ImWchar* self);
    ImFontConfig const * (* ImVector_ImFontConfig_front_const) (const ImVector_ImFontConfig* self);
    ImFontGlyph const * (* ImVector_ImFontGlyph_front_const) (const ImVector_ImFontGlyph* self);
    TextRange const * (* ImVector_TextRange_front_const) (const ImVector_TextRange* self);
    CustomRect const * (* ImVector_CustomRect_front_const) (const ImVector_CustomRect* self);
    ImDrawChannel const * (* ImVector_ImDrawChannel_front_const) (const ImVector_ImDrawChannel* self);
    char const * (* ImVector_char_front_const) (const ImVector_char* self);
    ImTextureID const * (* ImVector_ImTextureID_front_const) (const ImVector_ImTextureID* self);
    ImDrawVert const * (* ImVector_ImDrawVert_front_const) (const ImVector_ImDrawVert* self);
    int const * (* ImVector_int_front_const) (const ImVector_int* self);
    Pair const * (* ImVector_Pair_front_const) (const ImVector_Pair* self);
    ImFont* const * (* ImVector_ImFontPtr_front_const) (const ImVector_ImFontPtr* self);
    ImVec4 const * (* ImVector_ImVec4_front_const) (const ImVector_ImVec4* self);
    ImDrawCmd const * (* ImVector_ImDrawCmd_front_const) (const ImVector_ImDrawCmd* self);
    ImDrawIdx const * (* ImVector_ImDrawIdx_front_const) (const ImVector_ImDrawIdx* self);
    ImVec2 const * (* ImVector_ImVec2_front_const) (const ImVector_ImVec2* self);
    float* (* ImVector_float_back) (ImVector_float* self);
    ImWchar* (* ImVector_ImWchar_back) (ImVector_ImWchar* self);
    ImFontConfig* (* ImVector_ImFontConfig_back) (ImVector_ImFontConfig* self);
    ImFontGlyph* (* ImVector_ImFontGlyph_back) (ImVector_ImFontGlyph* self);
    TextRange* (* ImVector_TextRange_back) (ImVector_TextRange* self);
    CustomRect* (* ImVector_CustomRect_back) (ImVector_CustomRect* self);
    ImDrawChannel* (* ImVector_ImDrawChannel_back) (ImVector_ImDrawChannel* self);
    char* (* ImVector_char_back) (ImVector_char* self);
    ImTextureID* (* ImVector_ImTextureID_back) (ImVector_ImTextureID* self);
    ImDrawVert* (* ImVector_ImDrawVert_back) (ImVector_ImDrawVert* self);
    int* (* ImVector_int_back) (ImVector_int* self);
    Pair* (* ImVector_Pair_back) (ImVector_Pair* self);
    ImFont** (* ImVector_ImFontPtr_back) (ImVector_ImFontPtr* self);
    ImVec4* (* ImVector_ImVec4_back) (ImVector_ImVec4* self);
    ImDrawCmd* (* ImVector_ImDrawCmd_back) (ImVector_ImDrawCmd* self);
    ImDrawIdx* (* ImVector_ImDrawIdx_back) (ImVector_ImDrawIdx* self);
    ImVec2* (* ImVector_ImVec2_back) (ImVector_ImVec2* self);
    float const * (* ImVector_float_back_const) (const ImVector_float* self);
    ImWchar const * (* ImVector_ImWchar_back_const) (const ImVector_ImWchar* self);
    ImFontConfig const * (* ImVector_ImFontConfig_back_const) (const ImVector_ImFontConfig* self);
    ImFontGlyph const * (* ImVector_ImFontGlyph_back_const) (const ImVector_ImFontGlyph* self);
    TextRange const * (* ImVector_TextRange_back_const) (const ImVector_TextRange* self);
    CustomRect const * (* ImVector_CustomRect_back_const) (const ImVector_CustomRect* self);
    ImDrawChannel const * (* ImVector_ImDrawChannel_back_const) (const ImVector_ImDrawChannel* self);
    char const * (* ImVector_char_back_const) (const ImVector_char* self);
    ImTextureID const * (* ImVector_ImTextureID_back_const) (const ImVector_ImTextureID* self);
    ImDrawVert const * (* ImVector_ImDrawVert_back_const) (const ImVector_ImDrawVert* self);
    int const * (* ImVector_int_back_const) (const ImVector_int* self);
    Pair const * (* ImVector_Pair_back_const) (const ImVector_Pair* self);
    ImFont* const * (* ImVector_ImFontPtr_back_const) (const ImVector_ImFontPtr* self);
    ImVec4 const * (* ImVector_ImVec4_back_const) (const ImVector_ImVec4* self);
    ImDrawCmd const * (* ImVector_ImDrawCmd_back_const) (const ImVector_ImDrawCmd* self);
    ImDrawIdx const * (* ImVector_ImDrawIdx_back_const) (const ImVector_ImDrawIdx* self);
    ImVec2 const * (* ImVector_ImVec2_back_const) (const ImVector_ImVec2* self);
    void (* ImVector_float_swap) (ImVector_float* self,ImVector_float rhs);
    void (* ImVector_ImWchar_swap) (ImVector_ImWchar* self,ImVector_ImWchar rhs);
    void (* ImVector_ImFontConfig_swap) (ImVector_ImFontConfig* self,ImVector_ImFontConfig rhs);
    void (* ImVector_ImFontGlyph_swap) (ImVector_ImFontGlyph* self,ImVector_ImFontGlyph rhs);
    void (* ImVector_TextRange_swap) (ImVector_TextRange* self,ImVector_TextRange rhs);
    void (* ImVector_CustomRect_swap) (ImVector_CustomRect* self,ImVector_CustomRect rhs);
    void (* ImVector_ImDrawChannel_swap) (ImVector_ImDrawChannel* self,ImVector_ImDrawChannel rhs);
    void (* ImVector_char_swap) (ImVector_char* self,ImVector_char rhs);
    void (* ImVector_ImTextureID_swap) (ImVector_ImTextureID* self,ImVector_ImTextureID rhs);
    void (* ImVector_ImDrawVert_swap) (ImVector_ImDrawVert* self,ImVector_ImDrawVert rhs);
    void (* ImVector_int_swap) (ImVector_int* self,ImVector_int rhs);
    void (* ImVector_Pair_swap) (ImVector_Pair* self,ImVector_Pair rhs);
    void (* ImVector_ImFontPtr_swap) (ImVector_ImFontPtr* self,ImVector_ImFontPtr rhs);
    void (* ImVector_ImVec4_swap) (ImVector_ImVec4* self,ImVector_ImVec4 rhs);
    void (* ImVector_ImDrawCmd_swap) (ImVector_ImDrawCmd* self,ImVector_ImDrawCmd rhs);
    void (* ImVector_ImDrawIdx_swap) (ImVector_ImDrawIdx* self,ImVector_ImDrawIdx rhs);
    void (* ImVector_ImVec2_swap) (ImVector_ImVec2* self,ImVector_ImVec2 rhs);
    int (* ImVector_float__grow_capacity) (const ImVector_float* self,int sz);
    int (* ImVector_ImWchar__grow_capacity) (const ImVector_ImWchar* self,int sz);
    int (* ImVector_ImFontConfig__grow_capacity) (const ImVector_ImFontConfig* self,int sz);
    int (* ImVector_ImFontGlyph__grow_capacity) (const ImVector_ImFontGlyph* self,int sz);
    int (* ImVector_TextRange__grow_capacity) (const ImVector_TextRange* self,int sz);
    int (* ImVector_CustomRect__grow_capacity) (const ImVector_CustomRect* self,int sz);
    int (* ImVector_ImDrawChannel__grow_capacity) (const ImVector_ImDrawChannel* self,int sz);
    int (* ImVector_char__grow_capacity) (const ImVector_char* self,int sz);
    int (* ImVector_ImTextureID__grow_capacity) (const ImVector_ImTextureID* self,int sz);
    int (* ImVector_ImDrawVert__grow_capacity) (const ImVector_ImDrawVert* self,int sz);
    int (* ImVector_int__grow_capacity) (const ImVector_int* self,int sz);
    int (* ImVector_Pair__grow_capacity) (const ImVector_Pair* self,int sz);
    int (* ImVector_ImFontPtr__grow_capacity) (const ImVector_ImFontPtr* self,int sz);
    int (* ImVector_ImVec4__grow_capacity) (const ImVector_ImVec4* self,int sz);
    int (* ImVector_ImDrawCmd__grow_capacity) (const ImVector_ImDrawCmd* self,int sz);
    int (* ImVector_ImDrawIdx__grow_capacity) (const ImVector_ImDrawIdx* self,int sz);
    int (* ImVector_ImVec2__grow_capacity) (const ImVector_ImVec2* self,int sz);
    void (* ImVector_float_resize) (ImVector_float* self,int new_size);
    void (* ImVector_ImWchar_resize) (ImVector_ImWchar* self,int new_size);
    void (* ImVector_ImFontConfig_resize) (ImVector_ImFontConfig* self,int new_size);
    void (* ImVector_ImFontGlyph_resize) (ImVector_ImFontGlyph* self,int new_size);
    void (* ImVector_TextRange_resize) (ImVector_TextRange* self,int new_size);
    void (* ImVector_CustomRect_resize) (ImVector_CustomRect* self,int new_size);
    void (* ImVector_ImDrawChannel_resize) (ImVector_ImDrawChannel* self,int new_size);
    void (* ImVector_char_resize) (ImVector_char* self,int new_size);
    void (* ImVector_ImTextureID_resize) (ImVector_ImTextureID* self,int new_size);
    void (* ImVector_ImDrawVert_resize) (ImVector_ImDrawVert* self,int new_size);
    void (* ImVector_int_resize) (ImVector_int* self,int new_size);
    void (* ImVector_Pair_resize) (ImVector_Pair* self,int new_size);
    void (* ImVector_ImFontPtr_resize) (ImVector_ImFontPtr* self,int new_size);
    void (* ImVector_ImVec4_resize) (ImVector_ImVec4* self,int new_size);
    void (* ImVector_ImDrawCmd_resize) (ImVector_ImDrawCmd* self,int new_size);
    void (* ImVector_ImDrawIdx_resize) (ImVector_ImDrawIdx* self,int new_size);
    void (* ImVector_ImVec2_resize) (ImVector_ImVec2* self,int new_size);
    void (* ImVector_float_resizeT) (ImVector_float* self,int new_size,const float v);
    void (* ImVector_ImWchar_resizeT) (ImVector_ImWchar* self,int new_size,const ImWchar v);
    void (* ImVector_ImFontConfig_resizeT) (ImVector_ImFontConfig* self,int new_size,const ImFontConfig v);
    void (* ImVector_ImFontGlyph_resizeT) (ImVector_ImFontGlyph* self,int new_size,const ImFontGlyph v);
    void (* ImVector_TextRange_resizeT) (ImVector_TextRange* self,int new_size,const TextRange v);
    void (* ImVector_CustomRect_resizeT) (ImVector_CustomRect* self,int new_size,const CustomRect v);
    void (* ImVector_ImDrawChannel_resizeT) (ImVector_ImDrawChannel* self,int new_size,const ImDrawChannel v);
    void (* ImVector_char_resizeT) (ImVector_char* self,int new_size,const char v);
    void (* ImVector_ImTextureID_resizeT) (ImVector_ImTextureID* self,int new_size,const ImTextureID v);
    void (* ImVector_ImDrawVert_resizeT) (ImVector_ImDrawVert* self,int new_size,const ImDrawVert v);
    void (* ImVector_int_resizeT) (ImVector_int* self,int new_size,const int v);
    void (* ImVector_Pair_resizeT) (ImVector_Pair* self,int new_size,const Pair v);
    void (* ImVector_ImFontPtr_resizeT) (ImVector_ImFontPtr* self,int new_size,ImFont* const  v);
    void (* ImVector_ImVec4_resizeT) (ImVector_ImVec4* self,int new_size,const ImVec4 v);
    void (* ImVector_ImDrawCmd_resizeT) (ImVector_ImDrawCmd* self,int new_size,const ImDrawCmd v);
    void (* ImVector_ImDrawIdx_resizeT) (ImVector_ImDrawIdx* self,int new_size,const ImDrawIdx v);
    void (* ImVector_ImVec2_resizeT) (ImVector_ImVec2* self,int new_size,const ImVec2 v);
    void (* ImVector_float_reserve) (ImVector_float* self,int new_capacity);
    void (* ImVector_ImWchar_reserve) (ImVector_ImWchar* self,int new_capacity);
    void (* ImVector_ImFontConfig_reserve) (ImVector_ImFontConfig* self,int new_capacity);
    void (* ImVector_ImFontGlyph_reserve) (ImVector_ImFontGlyph* self,int new_capacity);
    void (* ImVector_TextRange_reserve) (ImVector_TextRange* self,int new_capacity);
    void (* ImVector_CustomRect_reserve) (ImVector_CustomRect* self,int new_capacity);
    void (* ImVector_ImDrawChannel_reserve) (ImVector_ImDrawChannel* self,int new_capacity);
    void (* ImVector_char_reserve) (ImVector_char* self,int new_capacity);
    void (* ImVector_ImTextureID_reserve) (ImVector_ImTextureID* self,int new_capacity);
    void (* ImVector_ImDrawVert_reserve) (ImVector_ImDrawVert* self,int new_capacity);
    void (* ImVector_int_reserve) (ImVector_int* self,int new_capacity);
    void (* ImVector_Pair_reserve) (ImVector_Pair* self,int new_capacity);
    void (* ImVector_ImFontPtr_reserve) (ImVector_ImFontPtr* self,int new_capacity);
    void (* ImVector_ImVec4_reserve) (ImVector_ImVec4* self,int new_capacity);
    void (* ImVector_ImDrawCmd_reserve) (ImVector_ImDrawCmd* self,int new_capacity);
    void (* ImVector_ImDrawIdx_reserve) (ImVector_ImDrawIdx* self,int new_capacity);
    void (* ImVector_ImVec2_reserve) (ImVector_ImVec2* self,int new_capacity);
    void (* ImVector_float_push_back) (ImVector_float* self,const float v);
    void (* ImVector_ImWchar_push_back) (ImVector_ImWchar* self,const ImWchar v);
    void (* ImVector_ImFontConfig_push_back) (ImVector_ImFontConfig* self,const ImFontConfig v);
    void (* ImVector_ImFontGlyph_push_back) (ImVector_ImFontGlyph* self,const ImFontGlyph v);
    void (* ImVector_TextRange_push_back) (ImVector_TextRange* self,const TextRange v);
    void (* ImVector_CustomRect_push_back) (ImVector_CustomRect* self,const CustomRect v);
    void (* ImVector_ImDrawChannel_push_back) (ImVector_ImDrawChannel* self,const ImDrawChannel v);
    void (* ImVector_char_push_back) (ImVector_char* self,const char v);
    void (* ImVector_ImTextureID_push_back) (ImVector_ImTextureID* self,const ImTextureID v);
    void (* ImVector_ImDrawVert_push_back) (ImVector_ImDrawVert* self,const ImDrawVert v);
    void (* ImVector_int_push_back) (ImVector_int* self,const int v);
    void (* ImVector_Pair_push_back) (ImVector_Pair* self,const Pair v);
    void (* ImVector_ImFontPtr_push_back) (ImVector_ImFontPtr* self,ImFont* const  v);
    void (* ImVector_ImVec4_push_back) (ImVector_ImVec4* self,const ImVec4 v);
    void (* ImVector_ImDrawCmd_push_back) (ImVector_ImDrawCmd* self,const ImDrawCmd v);
    void (* ImVector_ImDrawIdx_push_back) (ImVector_ImDrawIdx* self,const ImDrawIdx v);
    void (* ImVector_ImVec2_push_back) (ImVector_ImVec2* self,const ImVec2 v);
    void (* ImVector_float_pop_back) (ImVector_float* self);
    void (* ImVector_ImWchar_pop_back) (ImVector_ImWchar* self);
    void (* ImVector_ImFontConfig_pop_back) (ImVector_ImFontConfig* self);
    void (* ImVector_ImFontGlyph_pop_back) (ImVector_ImFontGlyph* self);
    void (* ImVector_TextRange_pop_back) (ImVector_TextRange* self);
    void (* ImVector_CustomRect_pop_back) (ImVector_CustomRect* self);
    void (* ImVector_ImDrawChannel_pop_back) (ImVector_ImDrawChannel* self);
    void (* ImVector_char_pop_back) (ImVector_char* self);
    void (* ImVector_ImTextureID_pop_back) (ImVector_ImTextureID* self);
    void (* ImVector_ImDrawVert_pop_back) (ImVector_ImDrawVert* self);
    void (* ImVector_int_pop_back) (ImVector_int* self);
    void (* ImVector_Pair_pop_back) (ImVector_Pair* self);
    void (* ImVector_ImFontPtr_pop_back) (ImVector_ImFontPtr* self);
    void (* ImVector_ImVec4_pop_back) (ImVector_ImVec4* self);
    void (* ImVector_ImDrawCmd_pop_back) (ImVector_ImDrawCmd* self);
    void (* ImVector_ImDrawIdx_pop_back) (ImVector_ImDrawIdx* self);
    void (* ImVector_ImVec2_pop_back) (ImVector_ImVec2* self);
    void (* ImVector_float_push_front) (ImVector_float* self,const float v);
    void (* ImVector_ImWchar_push_front) (ImVector_ImWchar* self,const ImWchar v);
    void (* ImVector_ImFontConfig_push_front) (ImVector_ImFontConfig* self,const ImFontConfig v);
    void (* ImVector_ImFontGlyph_push_front) (ImVector_ImFontGlyph* self,const ImFontGlyph v);
    void (* ImVector_TextRange_push_front) (ImVector_TextRange* self,const TextRange v);
    void (* ImVector_CustomRect_push_front) (ImVector_CustomRect* self,const CustomRect v);
    void (* ImVector_ImDrawChannel_push_front) (ImVector_ImDrawChannel* self,const ImDrawChannel v);
    void (* ImVector_char_push_front) (ImVector_char* self,const char v);
    void (* ImVector_ImTextureID_push_front) (ImVector_ImTextureID* self,const ImTextureID v);
    void (* ImVector_ImDrawVert_push_front) (ImVector_ImDrawVert* self,const ImDrawVert v);
    void (* ImVector_int_push_front) (ImVector_int* self,const int v);
    void (* ImVector_Pair_push_front) (ImVector_Pair* self,const Pair v);
    void (* ImVector_ImFontPtr_push_front) (ImVector_ImFontPtr* self,ImFont* const  v);
    void (* ImVector_ImVec4_push_front) (ImVector_ImVec4* self,const ImVec4 v);
    void (* ImVector_ImDrawCmd_push_front) (ImVector_ImDrawCmd* self,const ImDrawCmd v);
    void (* ImVector_ImDrawIdx_push_front) (ImVector_ImDrawIdx* self,const ImDrawIdx v);
    void (* ImVector_ImVec2_push_front) (ImVector_ImVec2* self,const ImVec2 v);
    float* (* ImVector_float_erase) (ImVector_float* self,float const * it);
    ImWchar* (* ImVector_ImWchar_erase) (ImVector_ImWchar* self,ImWchar const * it);
    ImFontConfig* (* ImVector_ImFontConfig_erase) (ImVector_ImFontConfig* self,ImFontConfig const * it);
    ImFontGlyph* (* ImVector_ImFontGlyph_erase) (ImVector_ImFontGlyph* self,ImFontGlyph const * it);
    TextRange* (* ImVector_TextRange_erase) (ImVector_TextRange* self,TextRange const * it);
    CustomRect* (* ImVector_CustomRect_erase) (ImVector_CustomRect* self,CustomRect const * it);
    ImDrawChannel* (* ImVector_ImDrawChannel_erase) (ImVector_ImDrawChannel* self,ImDrawChannel const * it);
    char* (* ImVector_char_erase) (ImVector_char* self,char const * it);
    ImTextureID* (* ImVector_ImTextureID_erase) (ImVector_ImTextureID* self,ImTextureID const * it);
    ImDrawVert* (* ImVector_ImDrawVert_erase) (ImVector_ImDrawVert* self,ImDrawVert const * it);
    int* (* ImVector_int_erase) (ImVector_int* self,int const * it);
    Pair* (* ImVector_Pair_erase) (ImVector_Pair* self,Pair const * it);
    ImFont** (* ImVector_ImFontPtr_erase) (ImVector_ImFontPtr* self,ImFont* const * it);
    ImVec4* (* ImVector_ImVec4_erase) (ImVector_ImVec4* self,ImVec4 const * it);
    ImDrawCmd* (* ImVector_ImDrawCmd_erase) (ImVector_ImDrawCmd* self,ImDrawCmd const * it);
    ImDrawIdx* (* ImVector_ImDrawIdx_erase) (ImVector_ImDrawIdx* self,ImDrawIdx const * it);
    ImVec2* (* ImVector_ImVec2_erase) (ImVector_ImVec2* self,ImVec2 const * it);
    float* (* ImVector_float_eraseTPtr) (ImVector_float* self,float const * it,float const * it_last);
    ImWchar* (* ImVector_ImWchar_eraseTPtr) (ImVector_ImWchar* self,ImWchar const * it,ImWchar const * it_last);
    ImFontConfig* (* ImVector_ImFontConfig_eraseTPtr) (ImVector_ImFontConfig* self,ImFontConfig const * it,ImFontConfig const * it_last);
    ImFontGlyph* (* ImVector_ImFontGlyph_eraseTPtr) (ImVector_ImFontGlyph* self,ImFontGlyph const * it,ImFontGlyph const * it_last);
    TextRange* (* ImVector_TextRange_eraseTPtr) (ImVector_TextRange* self,TextRange const * it,TextRange const * it_last);
    CustomRect* (* ImVector_CustomRect_eraseTPtr) (ImVector_CustomRect* self,CustomRect const * it,CustomRect const * it_last);
    ImDrawChannel* (* ImVector_ImDrawChannel_eraseTPtr) (ImVector_ImDrawChannel* self,ImDrawChannel const * it,ImDrawChannel const * it_last);
    char* (* ImVector_char_eraseTPtr) (ImVector_char* self,char const * it,char const * it_last);
    ImTextureID* (* ImVector_ImTextureID_eraseTPtr) (ImVector_ImTextureID* self,ImTextureID const * it,ImTextureID const * it_last);
    ImDrawVert* (* ImVector_ImDrawVert_eraseTPtr) (ImVector_ImDrawVert* self,ImDrawVert const * it,ImDrawVert const * it_last);
    int* (* ImVector_int_eraseTPtr) (ImVector_int* self,int const * it,int const * it_last);
    Pair* (* ImVector_Pair_eraseTPtr) (ImVector_Pair* self,Pair const * it,Pair const * it_last);
    ImFont** (* ImVector_ImFontPtr_eraseTPtr) (ImVector_ImFontPtr* self,ImFont* const * it,ImFont* const * it_last);
    ImVec4* (* ImVector_ImVec4_eraseTPtr) (ImVector_ImVec4* self,ImVec4 const * it,ImVec4 const * it_last);
    ImDrawCmd* (* ImVector_ImDrawCmd_eraseTPtr) (ImVector_ImDrawCmd* self,ImDrawCmd const * it,ImDrawCmd const * it_last);
    ImDrawIdx* (* ImVector_ImDrawIdx_eraseTPtr) (ImVector_ImDrawIdx* self,ImDrawIdx const * it,ImDrawIdx const * it_last);
    ImVec2* (* ImVector_ImVec2_eraseTPtr) (ImVector_ImVec2* self,ImVec2 const * it,ImVec2 const * it_last);
    float* (* ImVector_float_erase_unsorted) (ImVector_float* self,float const * it);
    ImWchar* (* ImVector_ImWchar_erase_unsorted) (ImVector_ImWchar* self,ImWchar const * it);
    ImFontConfig* (* ImVector_ImFontConfig_erase_unsorted) (ImVector_ImFontConfig* self,ImFontConfig const * it);
    ImFontGlyph* (* ImVector_ImFontGlyph_erase_unsorted) (ImVector_ImFontGlyph* self,ImFontGlyph const * it);
    TextRange* (* ImVector_TextRange_erase_unsorted) (ImVector_TextRange* self,TextRange const * it);
    CustomRect* (* ImVector_CustomRect_erase_unsorted) (ImVector_CustomRect* self,CustomRect const * it);
    ImDrawChannel* (* ImVector_ImDrawChannel_erase_unsorted) (ImVector_ImDrawChannel* self,ImDrawChannel const * it);
    char* (* ImVector_char_erase_unsorted) (ImVector_char* self,char const * it);
    ImTextureID* (* ImVector_ImTextureID_erase_unsorted) (ImVector_ImTextureID* self,ImTextureID const * it);
    ImDrawVert* (* ImVector_ImDrawVert_erase_unsorted) (ImVector_ImDrawVert* self,ImDrawVert const * it);
    int* (* ImVector_int_erase_unsorted) (ImVector_int* self,int const * it);
    Pair* (* ImVector_Pair_erase_unsorted) (ImVector_Pair* self,Pair const * it);
    ImFont** (* ImVector_ImFontPtr_erase_unsorted) (ImVector_ImFontPtr* self,ImFont* const * it);
    ImVec4* (* ImVector_ImVec4_erase_unsorted) (ImVector_ImVec4* self,ImVec4 const * it);
    ImDrawCmd* (* ImVector_ImDrawCmd_erase_unsorted) (ImVector_ImDrawCmd* self,ImDrawCmd const * it);
    ImDrawIdx* (* ImVector_ImDrawIdx_erase_unsorted) (ImVector_ImDrawIdx* self,ImDrawIdx const * it);
    ImVec2* (* ImVector_ImVec2_erase_unsorted) (ImVector_ImVec2* self,ImVec2 const * it);
    float* (* ImVector_float_insert) (ImVector_float* self,float const * it,const float v);
    ImWchar* (* ImVector_ImWchar_insert) (ImVector_ImWchar* self,ImWchar const * it,const ImWchar v);
    ImFontConfig* (* ImVector_ImFontConfig_insert) (ImVector_ImFontConfig* self,ImFontConfig const * it,const ImFontConfig v);
    ImFontGlyph* (* ImVector_ImFontGlyph_insert) (ImVector_ImFontGlyph* self,ImFontGlyph const * it,const ImFontGlyph v);
    TextRange* (* ImVector_TextRange_insert) (ImVector_TextRange* self,TextRange const * it,const TextRange v);
    CustomRect* (* ImVector_CustomRect_insert) (ImVector_CustomRect* self,CustomRect const * it,const CustomRect v);
    ImDrawChannel* (* ImVector_ImDrawChannel_insert) (ImVector_ImDrawChannel* self,ImDrawChannel const * it,const ImDrawChannel v);
    char* (* ImVector_char_insert) (ImVector_char* self,char const * it,const char v);
    ImTextureID* (* ImVector_ImTextureID_insert) (ImVector_ImTextureID* self,ImTextureID const * it,const ImTextureID v);
    ImDrawVert* (* ImVector_ImDrawVert_insert) (ImVector_ImDrawVert* self,ImDrawVert const * it,const ImDrawVert v);
    int* (* ImVector_int_insert) (ImVector_int* self,int const * it,const int v);
    Pair* (* ImVector_Pair_insert) (ImVector_Pair* self,Pair const * it,const Pair v);
    ImFont** (* ImVector_ImFontPtr_insert) (ImVector_ImFontPtr* self,ImFont* const * it,ImFont* const  v);
    ImVec4* (* ImVector_ImVec4_insert) (ImVector_ImVec4* self,ImVec4 const * it,const ImVec4 v);
    ImDrawCmd* (* ImVector_ImDrawCmd_insert) (ImVector_ImDrawCmd* self,ImDrawCmd const * it,const ImDrawCmd v);
    ImDrawIdx* (* ImVector_ImDrawIdx_insert) (ImVector_ImDrawIdx* self,ImDrawIdx const * it,const ImDrawIdx v);
    ImVec2* (* ImVector_ImVec2_insert) (ImVector_ImVec2* self,ImVec2 const * it,const ImVec2 v);
    bool (* ImVector_float_contains) (const ImVector_float* self,const float v);
    bool (* ImVector_ImWchar_contains) (const ImVector_ImWchar* self,const ImWchar v);
    bool (* ImVector_char_contains) (const ImVector_char* self,const char v);
    bool (* ImVector_int_contains) (const ImVector_int* self,const int v);
    int (* ImVector_float_index_from_ptr) (const ImVector_float* self,float const * it);
    int (* ImVector_ImWchar_index_from_ptr) (const ImVector_ImWchar* self,ImWchar const * it);
    int (* ImVector_ImFontConfig_index_from_ptr) (const ImVector_ImFontConfig* self,ImFontConfig const * it);
    int (* ImVector_ImFontGlyph_index_from_ptr) (const ImVector_ImFontGlyph* self,ImFontGlyph const * it);
    int (* ImVector_TextRange_index_from_ptr) (const ImVector_TextRange* self,TextRange const * it);
    int (* ImVector_CustomRect_index_from_ptr) (const ImVector_CustomRect* self,CustomRect const * it);
    int (* ImVector_ImDrawChannel_index_from_ptr) (const ImVector_ImDrawChannel* self,ImDrawChannel const * it);
    int (* ImVector_char_index_from_ptr) (const ImVector_char* self,char const * it);
    int (* ImVector_ImTextureID_index_from_ptr) (const ImVector_ImTextureID* self,ImTextureID const * it);
    int (* ImVector_ImDrawVert_index_from_ptr) (const ImVector_ImDrawVert* self,ImDrawVert const * it);
    int (* ImVector_int_index_from_ptr) (const ImVector_int* self,int const * it);
    int (* ImVector_Pair_index_from_ptr) (const ImVector_Pair* self,Pair const * it);
    int (* ImVector_ImFontPtr_index_from_ptr) (const ImVector_ImFontPtr* self,ImFont* const * it);
    int (* ImVector_ImVec4_index_from_ptr) (const ImVector_ImVec4* self,ImVec4 const * it);
    int (* ImVector_ImDrawCmd_index_from_ptr) (const ImVector_ImDrawCmd* self,ImDrawCmd const * it);
    int (* ImVector_ImDrawIdx_index_from_ptr) (const ImVector_ImDrawIdx* self,ImDrawIdx const * it);
    int (* ImVector_ImVec2_index_from_ptr) (const ImVector_ImVec2* self,ImVec2 const * it);
    void (* igLogText) (CONST char *fmt, ...);
    void (* ImGuiTextBuffer_appendf) (struct ImGuiTextBuffer *buffer, const char *fmt, ...);
    float (* igGET_FLT_MAX) ();
    void (* igColorConvertRGBtoHSV) (float r,float g,float b,float *out_h,float *out_s,float *out_v);
    void (* igColorConvertHSVtoRGB) (float h,float s,float v,float *out_r,float *out_g,float *out_b);
    ImVector_ImWchar* (* ImVector_ImWchar_create) ();
    void (* ImVector_ImWchar_Init) (ImVector_ImWchar* p);
    void (* ImVector_ImWchar_UnInit) (ImVector_ImWchar* p);
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

