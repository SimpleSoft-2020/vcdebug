// viewreg.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
int get_val(int ar1,int ar2,const char* ar3)
{
	int data = ar1 * ar1;
	return data;
}
int main(int argc, _TCHAR* argv[])
{
	get_val(100,200,"test");
	return 0;
}

