#pragma once

#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <mscoree.h>
#include <metahost.h>

#pragma comment(lib, "mscoree.lib")

#define BUFFER_SIZE 500

ICLRMetaHost *pMetaHost = NULL;
ICLRMetaHostPolicy *pMetaHostPolicy = NULL;
ICLRDebugging *pCLRDebugging = NULL;
ICLRControl *pCLRControl = NULL;
ICLRRuntimeInfo *pRuntimeInfo = NULL;
ICLRRuntimeHost * pRuntimeHost = NULL;


void StartTheDotNetRuntime(LPCWSTR runtimeVersion, LPCWSTR dllPath, LPCWSTR startClass, LPCWSTR startMethod, LPCWSTR startArgument)
{

    CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, (LPVOID*)&pMetaHost);
    CLRCreateInstance(CLSID_CLRMetaHostPolicy, IID_ICLRMetaHostPolicy, (LPVOID*)&pMetaHostPolicy);
    CLRCreateInstance(CLSID_CLRDebugging, IID_ICLRDebugging, (LPVOID*)&pCLRDebugging);

    DWORD dwVersion = 0;
    DWORD dwImageVersion = 0;
    pMetaHost->GetRuntime(runtimeVersion, IID_ICLRRuntimeInfo, (LPVOID*)&pRuntimeInfo);

    pRuntimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, (LPVOID*)&pRuntimeHost);

    pRuntimeHost->Start();

    DWORD dwRetCode = 0;
    pRuntimeHost->ExecuteInDefaultAppDomain(dllPath, startClass, startMethod, startArgument, &dwRetCode); 
}

void FreeTheDotNetRuntime() {
    if (pRuntimeHost != NULL) {
        pRuntimeHost->Stop();
        pRuntimeHost->Release();
    }
    if (pRuntimeInfo != NULL)
        pRuntimeInfo->Release();
    if (pCLRDebugging != NULL)
        pCLRDebugging->Release();
    if (pMetaHostPolicy != NULL)
        pMetaHostPolicy->Release();
    if (pMetaHost != NULL) {
        pMetaHost->Release();
    }
}