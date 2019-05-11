/**
 * @file sse-hooks.h
 * @brief Public C API for users of SSE Hooks
 * @internal
 *
 * This file is part of SSE Hooks project (aka SSE-ImGui).
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
 * @note This API is not thread-safe.
 * @note Unless mentioned, all strings are null-terminated and in UTF-8.
 *
 * @details
 * This file encompass all the functions which are presented to the users of
 * SSE-ImGui. The interface targets to be maximum compatible and portable
 * across the expected build and usage scenarios. This file uses generic C, but
 * is compatible with C++. As the methods are to be exported in the DLL, this
 * lib interface can be also accessed from other languages too.
 */

#ifndef SSEIMGUI_SSEGUI_H
#define SSEIMGUI_SSEGUI_H

#include <stdint.h>
#include <sse-imgui/platform.h>
#include <sse-imgui/imgui_wrapped.h>

/// To match a compiled in API against one loaded at run-time.
#define SSEIMGUI_API_VERSION (1)

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************/

/**
 * Run-time version of this API and its implementation details.
 *
 * This function can be used to detect in run-time what kind of feature & fixes
 * on the API, the loaded file is compiled with. This function is the only one,
 * which is guaranteed to preseve through the whole lifecycle of this product.
 *
 * The @param api tells what version is the current API. Any version different
 * than the one expected guarantees a broken interface. Most likely it will
 * mean that a function is missing or its prototype is different.
 *
 * The @param maj describes major, but compatible changes within the API. Maybe
 * a new function is added or the behaviour of an old one was extended in
 * compatible way i.e. it won't break the callee.
 *
 * The @param imp is an implementation detail, in most cases may not be of
 * interest. It is reserved for patches, bug fixes, maybe documentation updates
 * re-release of something and etc.
 *
 * It is advised to check @param api against #SSEIMGUI_API_VERSION.
 *
 * @param[out] api (optional) non-portable
 * @param[out] maj (optional) new features and enhancements
 * @param[out] imp (optional) patches
 * @param[out] timestamp (optional) in ISO format
 */

SSEIMGUI_API void SSEIMGUI_CCONV
sseimgui_version (int* api, int* maj, int* imp, const char** timestamp);

/** @see #sseimgui_version() */

typedef void (SSEIMGUI_CCONV* sseimgui_version_t) (int*,int*,int*,const char**);

/******************************************************************************/

/**
 * Report the last message in more human-readable form.
 *
 * @param[in,out] size in bytes of @param message, on exit how many bytes were
 * actually written (excluding the terminating null) or how many bytes are
 * needed in order to get the full message. Can be zero, if there is no error.
 *
 * @param[out] message in human readable form, can be nullptr if @param size is
 * needed to pre-allocate a buffer.
 */

SSEIMGUI_API void SSEIMGUI_CCONV
sseimgui_last_error (size_t* size, char* message);

/** @see #sseimgui_last_error() */

typedef void (SSEIMGUI_CCONV* sseimgui_last_error_t) (size_t*, char*);

/******************************************************************************/

/**
 * Change the SSE ImGui activation key.
 *
 * The control key is one of the Windows VIK_* constants used to toggle the
 * input capturing. Rendering is always active and is up to the ImGui plugins
 * to decided whether they want to render during disabled input or no.
 *
 * @see https://docs.microsoft.com/en-us/windows/desktop/inputdev/virtual-key-codes
 * @param[in,out] vik constant to be used from now on, if the param is negative
 *  or out of bounds (>255) it won't change the constant. On exit it will
 *  contain the previous, or the current (if not changed) key used.
 */

SSEIMGUI_API void SSEIMGUI_CCONV
sseimgui_activation_key (int* dik);

/** @see #sseimgui_activation_key() */

typedef void (SSEIMGUI_CCONV* sseimgui_activation_key_t) (int*);

/******************************************************************************/

/**
 * Type of callback invoked on each frame, parameter says whether SSE ImGui
 * is active (capturing input) or not.
 */

typedef void (SSEIMGUI_CCONV* sseimgui_render_callback) (int active);

/**
 * Register or remove a render listener
 *
 * These functions are invoked on each frame rendering, so plug ins can render
 * elements above or something. Note that, less and faster is better, or the
 * FPS can suffer.
 *
 * @param[in] callback to call or @param remove
 * @param[in] remove if positive, append if zero.
 */

SSEIMGUI_API void SSEIMGUI_CCONV
sseimgui_render_listener (sseimgui_render_callback callback, int remove);

/** @see #sseimgui_render_listener() */

typedef void (SSEIMGUI_CCONV* sseimgui_render_listener_t)
    (sseimgui_render_callback, int);

/******************************************************************************/

/**
 * Execute custom command.
 *
 * This is highly implementation specific and may change any moment. It is like
 * patch hole for development use.
 *
 * @param[in] command identifier
 * @param[in,out] arg to pass in or out data
 * @returns non-zero on success
 */

SSEIMGUI_API int SSEIMGUI_CCONV
sseimgui_execute (const char* command, void* arg);

/** @see #sseimgui_execute() */

typedef int (SSEIMGUI_CCONV* sseimgui_execute_t) (const char*, void*);

/******************************************************************************/

/**
 * Set of function pointers as found in this file.
 *
 * Compatible changes are function pointers appened to the end of this
 * structure.
 */

struct sseimgui_api_v1
{
    /** @see #sseimgui_version() */
    sseimgui_version_t version;
    /** @see #sseimgui_last_error() */
    sseimgui_last_error_t last_error;
    /** @see #sseimgui_activation_key() */
    sseimgui_activation_key_t activation_key;
    /** @see #sseimgui_render_listener() */
    sseimgui_render_listener_t render_listener;
    /** @see #sseimgui_make_imgui_api() */
    sseimgui_make_imgui_api_t make_imgui_api;
    /** @see #sseimgui_execute() */
    sseimgui_execute_t execute;
};

/** Points to the current API version in use. */
typedef struct sseimgui_api_v1 sseimgui_api;

/******************************************************************************/

/**
 * Create an instance of #sseimgui_api, ready for use.
 *
 * @returns an API
 */

SSEIMGUI_API sseimgui_api SSEIMGUI_CCONV
sseimgui_make_api ();

/** @see #sseimgui_make_api() */

typedef sseimgui_api (SSEIMGUI_CCONV* sseimgui_make_api_t) ();

/******************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* SSEIMGUI_SSEGUI_H */

/* EOF */

