#include "pig.h"


pig::pig(void)
{
}


pig::~pig(void)
{
}
void pig::eat()
{
	std::cout << "pig eat" << std::endl;
}
void pig::eat(const char* something)
{
	std::cout << "pig eat " << something << std::endl;
}