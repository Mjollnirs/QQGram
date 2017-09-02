#pragma once

#define  BASE_API  extern "C" __declspec(dllexport)

HMODULE Initialise();
BOOL Uninitialise();

BASE_API int AddDisableCloseHandle();
BASE_API int RemoveDisableCloseHandle();
BASE_API int RunQQHummerEngine();
BASE_API int SetDmpUin();
BASE_API int SetSeparateFreeMonitorPoint();
BASE_API int UninitializeCom();