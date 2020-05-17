// section_10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
int test(int i,int j)
{
	int x = i + j;
	return x;
}

int main(int argc, char* argv[])
{
	int x = test(10,20);
	printf("x is %d\n",x);
	return 0;
}

