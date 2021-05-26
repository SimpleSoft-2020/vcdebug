// funbreak.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "pig.h"
#include "dog.h"

int eat(int i)
{
	std::cout << "eat " << i << std::endl;
	return i;
}
void eat()
{
}
int main(int argc, _TCHAR* argv[])
{
	animal *ani=new dog();
	animal *ani2=new pig();
	ani->eat();
	ani->eat("bone");
	ani2->eat();
	ani2->eat("rice");
	eat(100);
	delete ani;
	delete ani2;
	return 0;
}

