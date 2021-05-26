// databreak.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

int data=100;
char str1[10];
char str2[5];
void test(int val)
{
	data = val;
}
void test1()
{
	strcpy(str1,"hello");
}
void test2()
{
	strcpy(str2,"this is a test text");
}

int main(int argc, _TCHAR* argv[])
{
	test(200);
	printf("data=%d\n",data);
	test(200);
	test(300);
	test1();
	test2();
	printf("str1=%s\n",str1);
	return 0;
}

