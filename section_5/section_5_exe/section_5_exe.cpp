// section_5_exe.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>

#include "../section_5_dll/section_5_dll.h"

void test_dll_static()
{
	int x = add(3,10);
	int y = sub(13,3);
}

void test_dll_dynamic()
{
	typedef int (* PADD)(int,int);
	typedef int (* PSUB)(int,int);
	HMODULE module = LoadLibrary("section_5_dll.dll");
	if(!module)
	{
		printf("can't load the dll\n");
		return;
	}
	PADD addf = (PADD)GetProcAddress(module,"add");
	if(!addf)
	{
		printf("can't find the func add\n");
		return;
	}
	PSUB subf =(PSUB)GetProcAddress(module,"sub");
	if(!subf)
	{
		printf("can't find the func sub\n");
		return;
	}
	int x = addf(3,10);
	int y = subf(13,3);
	FreeLibrary(module);
}
int _tmain(int argc, _TCHAR* argv[])
{
	//test_dll_dynamic();
	test_dll_static();
	return 0;
}

