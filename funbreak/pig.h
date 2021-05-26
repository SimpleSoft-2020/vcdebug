#pragma once
#include "animal.h"
class pig :
	public animal
{
public:
	pig(void);
	virtual ~pig(void);
	virtual void eat();
	virtual void eat(const char*something);
};

