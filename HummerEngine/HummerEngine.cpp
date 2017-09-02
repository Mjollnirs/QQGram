// HummerEngine.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

FARPROC addDisableCloseHandle;
FARPROC removeDisableCloseHandle;
FARPROC runQQHummerEngine;
FARPROC setDmpUin;
FARPROC setSeparateFreeMonitorPoint;
FARPROC uninitializeCom;

HMODULE core;

HMODULE Initialise() {
#ifdef _DEBUG
    MessageBox(NULL, L"HummerEngine Initialise...", L"Debug Mode", 0);
#endif // 

    HMODULE hummerEngine = LoadLibrary(L"HummerEngineBase.dll");
    HMODULE hummerEngineBase = hummerEngine;
    if (hummerEngine)
    {
        addDisableCloseHandle = GetProcAddress(hummerEngine, "AddDisableCloseHandle");
        removeDisableCloseHandle = GetProcAddress(hummerEngineBase, "RemoveDisableCloseHandle");
        runQQHummerEngine = GetProcAddress(hummerEngineBase, "RunQQHummerEngine");
        setDmpUin = GetProcAddress(hummerEngineBase, "SetSeparateFreeMonitorPoint");
        setSeparateFreeMonitorPoint = GetProcAddress(hummerEngineBase, "SetSeparateFreeMonitorPoint");
        uninitializeCom = GetProcAddress(hummerEngineBase, "UninitializeCom");
    }
    core = LoadLibrary(L"QQGram/Core.dll");
    if (!core)
    {
        MessageBox(NULL, TEXT("Core Load Failed!"), TEXT("Title"), 0);
    }
    return core;
}

BOOL Uninitialise()
{
    //if (core)
    //{
    //    FreeLibrary(core);
    //}

    return TRUE;
}

BASE_API int AddDisableCloseHandle()
{
    return addDisableCloseHandle();
}

BASE_API int RemoveDisableCloseHandle()
{
    return removeDisableCloseHandle();
}

BASE_API int RunQQHummerEngine()
{
    return runQQHummerEngine();
}

BASE_API int SetDmpUin()
{
    return setDmpUin();
}

BASE_API int SetSeparateFreeMonitorPoint()
{
    return setSeparateFreeMonitorPoint();
}

BASE_API int UninitializeCom()
{
    return uninitializeCom();
}
