/* Patch up the DDSTextureLoader due to some assumptions made from other devs */
#pragma once

#ifndef   NTDDI_VERSION
#  define NTDDI_VERSION NTDDI_VISTA
#endif

#ifndef   WINVER
#  define WINVER 0x0600 /* VISTA (high part of NDDI_VISTA?) */
#endif

#ifndef   _WIN32_WINNT
#  define _WIN32_WINNT 0x0600 /* VISTA */
#endif

#if __GNUC__ < 6 /* Not sure about the number, but MinGW 5.3 breaks, while 8.3 is okay */
#  define _In_
#  define _In_z_
#  define _In_reads_bytes_(x)
#  define _In_reads_opt_(x)
#  define _In_reads_(x)
#  define _Outptr_opt_
#  define _Out_opt_
#  define _Out_writes_(x)
#  define _Use_decl_annotations_
#  define _Analysis_assume_(x)
#endif

#include "DDSTextureLoader_.h"

#ifdef   UNREFERENCED_PARAMETER
#  undef UNREFERENCED_PARAMETER /* shouldn't be a big problem to have it this way */
#endif
#define  UNREFERENCED_PARAMETER(x) (void)(x)

