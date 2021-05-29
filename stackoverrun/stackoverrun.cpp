// compile with: /c /W1
#include <cstring>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable : 4996)   // for strcpy use


void test()
{
	char buffer[4];
	strcpy(buffer,"this is a  test string");
	char buffer2[10];
	strcpy(buffer2,"this is a test string");

}
int main() 
{
	test();
	return 0;
}