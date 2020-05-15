// section_6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <crtdbg.h>
#include <malloc.h>
#include "test.h"
#include <assert.h>
void new_test()
{
	int *test1 = new int[100];
	int *test2 = new int[16];
	memset(test2,0,16);
}
void memory_test()
{
	for(int i=0;i<2048;i++)
	{
		char* test = new char[1024*1024];
	}
}
void malloc_test()
{
	char *test1 = (char*)malloc(100);
	char *test2 = (char*)malloc(6);
	//memcpy(test2,"1234567890",10);

}
int main(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF  );
	//_CrtSetBreakAlloc(77);
	//memory_test();
	//*
	new_test();
	malloc_test();
	test_new();
	test_malloc();
	assert(_CrtCheckMemory());
	//*/
	return 0;
}

