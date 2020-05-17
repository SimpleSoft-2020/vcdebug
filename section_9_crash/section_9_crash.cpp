// section_10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <Dbghelp.h>
#include <stdio.h>

LONG WINAPI handle_exception(LPEXCEPTION_POINTERS lpExceptionInfo);
void throw_exception_test()
{
	throw 123;
}
void catch_test()
{
	try
	{
		throw_exception_test();
	}
	catch(...)
	{
		printf("catch exception\n");
	}
}
void exception_test()
{
	try
	{
		int x=0;
		int y = 10 / x;
	}
	catch(...)
	{
		printf("exception occurred\n");
	}

}
void crash_test()
{
	try
	{
		char* test = NULL;
		strcpy(test,"123");
	}
	catch(...)
	{
		printf("exception\n");
	}
}
int main(int argc, char *argv[])
{
    SetUnhandledExceptionFilter(handle_exception);
    //exception_test();
	crash_test(); 
	catch_test();
	printf("quit\n");

    return 0;
}
 
int GenerateMiniDump(PEXCEPTION_POINTERS exception_pointers)
{
    TCHAR file_name[MAX_PATH] = {0};	
    SYSTEMTIME local_time;
    GetLocalTime(&local_time);
    sprintf(file_name,"section_9_crash-%04d%02d%02d-%02d%02d%02d.dmp",local_time.wYear, local_time.wMonth, local_time.wDay,
        local_time.wHour, local_time.wMinute, local_time.wSecond);
    HANDLE h_dump_file = CreateFile(file_name, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE | FILE_SHARE_READ, 0, CREATE_ALWAYS, 0, 0);
    if (INVALID_HANDLE_VALUE == h_dump_file)
    {
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    MINIDUMP_EXCEPTION_INFORMATION exception_information;
    exception_information.ThreadId = GetCurrentThreadId();
    exception_information.ExceptionPointers = exception_pointers;
    exception_information.ClientPointers = FALSE;
	//MiniDumpNormal
	//MiniDumpWithDataSegs
	//MiniDumpWithFullMemory
    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), 
        h_dump_file, MiniDumpWithFullMemory, (exception_pointers ? &exception_information : NULL), NULL, NULL);
    CloseHandle(h_dump_file);
    return EXCEPTION_EXECUTE_HANDLER;
}
 
LONG WINAPI handle_exception(LPEXCEPTION_POINTERS lpExceptionInfo)
{
    return GenerateMiniDump(lpExceptionInfo);
}