
#include <iostream>
#include "test_base.h"
#pragma warning(disable : 4996)  

char gbuffer[5];
/*
堆溢出示例
*/
void heap_buffer_overflow(int opt)
{
	switch (opt)
	{
	case 0:
	{
		//new 缓冲区溢出
		char* str = new char[5];
		memset(str, 0, 10);
		delete[]str;
		break;
	}
	case 1:
	{
		//malloc 缓冲区溢出
		char* str = (char*)malloc(5);
		memset(str, 0, 6);
		free(str);
		break;
	}
	case 2:
	{
		//不正确的强制转换
		test_base* p = new test_base;
		testc* test = (testc*)p;
		test->val = 10;
		break;
	}
	
	}
}
/*
全局缓冲区溢出示例
*/

void global_buffer_overflow(int opt)
{
	switch (opt)
	{
	case 0:
	{
		//全局变量 
		strcpy(gbuffer, "this is a test");
		break;
	}
	case 1:
	{

		//静态变量
		static char sbuf[5];
		strcpy(sbuf, "this is a test");
		break;
	}	
	case 2:
	{
		//字符串常量
		const char* str = "12345";
		char c = str[10];
		break;

	}
	
	}
	//
}
/*
栈缓冲区溢出示例
*/
void stack_buffer_overflow(int opt)
{
	switch (opt)
	{
		
	case 0:
	{
		//经典的栈缓冲区溢出
		char x[10];
		memset(x, 0, 10);
		strcpy(x, "this is a test string");
		break;
	}
	case 1:
	{
		//读取溢出
		char x[10];
		memset(x, 0, 10);
		int res = x[11];
		break;
	}
	case 2:
	{
		//堆栈上的不正确强制转换
		test_base p;
		testc* test = (testc*)&p;
		test->val = 10;

		break;
	}
	}
	
}
/*
double-free示例
*/
void double_free(int opt)
{
	switch (opt)
	{
	case 0:
	{
		int* p = new int[4];
		p[0] = 100;
		delete[]p;
		delete[]p;
		break;
	}
	case 1:
	{
		testc* p = new testc();
		delete p;
		delete p;
		break;
	}
	}
}

/*
释放后再使用
*/
void use_after_free(int opt)
{
	switch (opt)
	{
	case 0:
	{
		char* str = (char*)malloc(5);
		strcpy(str, "test");
		free(str);
		char c = str[0];
	}
	case 1:
	{
		testc * p = new testc();
		p->val = 100;
		delete p;
		int i = p->val;
		break;
	}
	}
}
int main()
{	
	//global_buffer_overflow(2);
	//heap_buffer_overflow(2);
	//stack_buffer_overflow(1);
	//double_free(1);
	use_after_free(1);
	return 0;
}
