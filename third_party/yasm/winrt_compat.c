
/*
 This header is injected using /FI cl.exe flag for re2c project.
*/

#include "winrt_compat.h"

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
)
{
  CREATEFILE2_EXTENDED_PARAMETERS params;
  memset(&params, 0, sizeof(params));
  params.dwSize = sizeof(CREATEFILE2_EXTENDED_PARAMETERS);

  DWORD filter = FILE_ATTRIBUTE_ARCHIVE | 
                 FILE_ATTRIBUTE_ENCRYPTED |
                 FILE_ATTRIBUTE_HIDDEN |
                 FILE_ATTRIBUTE_INTEGRITY_STREAM |
                 FILE_ATTRIBUTE_NORMAL |
                 FILE_ATTRIBUTE_OFFLINE |
                 FILE_ATTRIBUTE_READONLY |
                 FILE_ATTRIBUTE_SYSTEM |
                 FILE_ATTRIBUTE_TEMPORARY;

  DWORD attribs = dwFlagsAndAttributes & (filter);
  DWORD flags = (dwFlagsAndAttributes | filter) ^ filter;

  params.dwFileAttributes = attribs;
  params.dwFileFlags = flags;
  params.lpSecurityAttributes = lpSecurityAttributes;
  params.hTemplateFile = hTemplateFile;

  return CreateFile2(
      lpFileName,
      dwDesiredAccess,
      dwShareMode,
      dwCreationDisposition,
      &params
    );
}

#ifdef __cplusplus
  }
#endif /* __cplusplus */
  