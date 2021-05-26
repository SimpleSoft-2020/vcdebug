#pragma once
#include <iostream>
class animal
{
public:
	animal(void);
	virtual ~animal(void);
public:
	virtual void eat();
	virtual void eat(const char*something);
};

