// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
void init()
{
	//do something
}
void uninit()
{
	//do someting
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		printf("Process Attached\n");
		init();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		uninit();
		printf("Process Detached\n");
		break;
	}
	return TRUE;
}

