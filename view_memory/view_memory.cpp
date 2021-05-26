// view_memory.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
struct test_s
{
	char c;
	int i;
	double d;

};
class test_c
{
public:
	test_c(){}
	~test_c(){}
public:
	char c;
	double d;
	int i;
};

void test_view_memory()
{
	const char test[]= "hello world";
	const wchar_t wtest[]=L"hello world";
	int len=strlen(test);
	int wlen=wcslen(wtest);
	int itest=0x12345678;
	printf("test=%s,wtest=%S,itest=%d\n",test,wtest,itest);

	struct test_s tests;
	tests.c='a';
	tests.d=12345.678;
	tests.i=0xaabbccdd;
	test_c testc;
	testc.c='a';
	testc.d=12345.678;
	testc.i=0xaabbccdd;
}
void file_test()
{
	char buffer[100]={0};
	FILE *file= fopen("test.txt","r");
	if(file)
	{
		fread(buffer,100,1,file);
		fclose(file);
	}
}
int main(int argc, _TCHAR* argv[])
{	
	test_view_memory();
	file_test();
	return 0;
}

