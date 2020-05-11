// section_2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include<iostream>
#include <Windows.h>
using namespace std;

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
//condition is true
void condition_test(int num)
{
	for(int i=2;i<num;i++)
	{
		bool res = is_prime(i);
		if(res)
		{
			cout << i << " is prime number" << endl;
		}		
	}
}
//values changed
void condition_test2(int type)
{
	int val=type;
	val++;
	//do something
	
}
//n!
int get_factorial(int n)
{
	if(n <=1)
		return 1;
	int res = 1;
	for(int i=1;i<=n;i++)
	{
		res *= i;
	}
	return res;
}
//注意一点，跳过执行的某些代码一定要与执行到的代码没有直接关系的，不然会出错

void multiple_times_skip_test()
{
	int n1=5;
	int n2=6;
	int res1 = get_factorial(n1);
	cout << n1 << " factorial is " << res1 << endl;
	int res2 = get_factorial(n2);
	cout << n2 << " factorial is " << res2 << endl;
}
int main(int argc, _TCHAR* argv[])
{
	condition_test(1001);
	condition_test2(100);
	condition_test2(100);
	condition_test2(101);
	multiple_times_skip_test();
	//remove a file
	char *file_name = "F:/testdir2";
	remove(file_name);
	
	return 0;
}

