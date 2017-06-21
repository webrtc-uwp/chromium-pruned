
/*
 This header is injected using /FI cl.exe flag for re2c project.
*/

#pragma once

#include <windows.h>

#define CreateFileW(xFileName,xAccess,xSharedMode,xSecuriteParams,xCreationDisposition,xFlagsAndAttributes,xTemplateFile) \
	winrtCreateFileW(xFileName,xAccess,xSharedMode,xSecuriteParams,xCreationDisposition,xFlagsAndAttributes,xTemplateFile)

#ifdef __cplusplus
  extern "C" {
#endif /* __cplusplus */

HANDLE WINAPI winrtCreateFileW(
  LPCWSTR               lpFileName,
  DWORD                 dwDesiredAccess,
  DWORD                 dwShareMode,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD                 dwCreationDisposition,
  DWORD                 dwFlagsAndAttributes,
  HANDLE                hTemplateFile
);

#ifdef __cplusplus
  }
#endif /* __cplusplus */
