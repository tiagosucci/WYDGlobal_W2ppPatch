// dllmain.cpp : Define o ponto de entrada para o aplicativo DLL.
#include "pch.h"
#include "Console.h"



 __declspec(dllexport) BOOL APIENTRY DllMain(HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
 
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        
        CreateConsole("W2GlobalPatch");
        if (!Singleton<ClientPatch>::instance().Initialize())
        {
            MessageBox(NULL, L"Can't read W2GlobalPatch", L"ERROR", NULL);
            return TRUE;
        }

       
    }
    break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

