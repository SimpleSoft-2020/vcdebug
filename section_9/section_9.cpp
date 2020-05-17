// section_9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int g_data_1 = 0;
int g_data_2 = 0;
HANDLE mutex_1 = NULL;
HANDLE mutex_2 = NULL;
DWORD WINAPI ThreadFun_1(LPVOID lp)
{
	//加锁,操作g_data_1
	cout << "Enter Thread Fun 1 \n";
	WaitForSingleObject(mutex_1, INFINITE); 
	Sleep(1000);
	g_data_1++;
	//加锁,操作g_data_2
	WaitForSingleObject(mutex_2, INFINITE); 
	g_data_2++;
	ReleaseMutex(mutex_2);
	ReleaseMutex(mutex_1);
	cout << "Thread Fun 1 exited\n";
	return 0;
}
DWORD WINAPI ThreadFun_2(LPVOID lp)
{
	cout << "Enter Thread Fun 2 \n";
	//加锁,操作g_data_2
	WaitForSingleObject(mutex_2, INFINITE); 
	g_data_2++;
	//加锁,操作g_data_1
	WaitForSingleObject(mutex_1, INFINITE); 
	g_data_1++;
	ReleaseMutex(mutex_2);
	ReleaseMutex(mutex_1);

	cout << "Thread Fun 2 exited\n";
	
	return 0;
}
int main(int argc, _TCHAR* argv[])
{
	mutex_1 = CreateMutex(NULL,FALSE,"mutex_1");
	mutex_2 = CreateMutex(NULL,FALSE,"mutex_2");
	DWORD thread_id_1 = 0;
	DWORD thread_id_2 = 0;
	HANDLE handles[2];
	
	HANDLE thread1 = CreateThread(NULL,0,ThreadFun_1,NULL,0,&thread_id_1);
	HANDLE thread2 = CreateThread(NULL,0,ThreadFun_2,NULL,0,&thread_id_2);
	handles[0]=thread1;
	handles[1]=thread2;
	WaitForMultipleObjects(2,handles,true,INFINITE);
	cout << "Exit the program\n";
	return 0;
}

