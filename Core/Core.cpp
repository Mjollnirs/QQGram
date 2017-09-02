// Core.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "CLRLoader.h"

unsigned threadId;

BOOL Initialise() {
    CreateThread(NULL, NULL, Loop, NULL, NULL, NULL);
    //_beginthreadex(0, 0, (unsigned int(__stdcall *)(void *))Loop, NULL, 0, &threadId);
    
    return TRUE;
}

BOOL Uninitialise() {
    FreeTheDotNetRuntime();
    return TRUE;
}

DWORD WINAPI Loop(LPVOID pvoid) {
    wchar_t* currentDir = new wchar_t[BUFFER_SIZE];
    CString &fullPath = *new CString();

    GetCurrentDirectoryW(BUFFER_SIZE, currentDir);
    fullPath.Append(currentDir);
    fullPath.Append(L"\\QQGram\\CLRHandler.dll");

    StartTheDotNetRuntime(L"v4.0.30319", fullPath, L"CLRHandler.EntryPoint", L"Entry", L"");

    free(currentDir);
    return 1;
}
