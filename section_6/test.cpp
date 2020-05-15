#include <stdafx.h>
#include "test.h"
#include <crtdbg.h>
#include <malloc.h>

#ifdef _DEBUG
#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define   malloc(s)  _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

void test_new()
{
	int *test1 = new int[100];
	int *test2 = new int[16];
	memset(test2,0,16);

}
void test_malloc()
{
	char *test1 = (char*)malloc(100);
	char *test2 = (char*)malloc(16);
	memset(test2,1,16);

}