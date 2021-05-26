#pragma once
#include "animal.h"
class dog :
	public animal
{
public:
	dog(void);
	virtual ~dog(void);
	virtual void eat();
	virtual void eat(const char*something);
};

