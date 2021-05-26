#include "animal.h"


animal::animal(void)
{
}


animal::~animal(void)
{
}
void animal::eat()
{
	std::cout << "eat" << std::endl;
}
void animal::eat(const char* something)
{
	std::cout << "eat " << something << std::endl;
}