#pragma once

BOOL Initialise();
BOOL Uninitialise();
DWORD WINAPI Loop(PVOID pvoid);
void StartTheDotNetRuntime(LPCWSTR runtimeVersion, LPCWSTR dllPath, LPCWSTR startClass, LPCWSTR startMethod, LPCWSTR startArgument);