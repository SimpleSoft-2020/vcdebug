// compile with: /c /W1
#include <cstring>
#include <stdlib.h>
#include <iostream>
#pragma warning(disable : 4996)   // for strcpy use



int main() {

	static char bu[10];
	std::cout << std::endl;
   char large_buffer[] = "This string is longer than 10 characters!!";
         strcpy(bu, large_buffer); // overrun buffer !!!

}