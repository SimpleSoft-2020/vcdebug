// section_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include <Windows.h>
using namespace std;


bool copy_file(const char* src_file_name,const char* dest_file_name)
{
	FILE* file_src = fopen(src_file_name,"rb");
	if(!file_src)
	{
		cout << "can't open  the file " << src_file_name << endl;
		return false;
	}
	FILE *file_dest = fopen(dest_file_name,"r+b");
	if(!file_src)
	{
		cout << "can't open  the file " << dest_file_name << endl;
		fclose(file_src);
		return false;
	}
	const int buffer_size = 65536;
	char buffer[buffer_size];
	while(true)
	{
		size_t read_size = fread(buffer,buffer_size,1,file_src);
		fwrite(buffer,buffer_size,1,file_dest);
		if(read_size < buffer_size)
			break;
	}
	fclose(file_src);
	fclose(file_dest);
	return true;
}
bool is_prime(int number)
{
	if(number <=2)
		return true;
	for(int i=2;i<number;i++)
	{
		if(number % i==0)
			return false;
	}
	return true;
}
void edit_continue_test()
{
	int number = 10;
	bool res = is_prime(number);
	if(res)
	{
		cout << number << " is prime" << endl;
	}
}
int main(int argc, _TCHAR* argv[])
{
	edit_continue_test();
	//remove a file
	remove("F:/testdir");
	int last_err = GetLastError();
	const char* src_file_name = "test1.txt";
	const char* dest_file_name = "test2.txt";
	bool res = copy_file(src_file_name,dest_file_name);
	if(res)
	{
		cout << "copy file successfully!" << endl;
	}
	else
	{
		cout << "copy file failed!" << endl;
	}
	return 0;
}

