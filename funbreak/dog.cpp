#include "dog.h"


dog::dog(void)
{
}


dog::~dog(void)
{
}

void dog::eat()
{
	std::cout << "dog eat" << std::endl;
}
void dog::eat(const char* something)
{
	std::cout << "dog eat " << something << std::endl;
}