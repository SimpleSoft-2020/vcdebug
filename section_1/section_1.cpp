// section_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include <assert.h>
class student
{
public:
	student(const char*name,int score)
	{
		assert(name != NULL);
		int len = strlen(name);
		_name = new char[len+1];
		strcpy(_name,name);
		_score = score;
	}
	~student()
	{
		delete []_name;
	}
	const char*name()
	{
		return _name;
	}
	int score()
	{
		return _score;
	}
private:
	char *_name;
	int _score;
};
void test_loop(int num)
{
	for(int i=0;i<num;i++)
	{
		int j = i* i;
		//do something
		printf("j is %d\n",j);

	}
}
void print_student(student& stu)
{
	printf("name:%s,score:%d\n",stu.name(),stu.score());
}
int main(int argc, _TCHAR* argv[])
{
	test_loop(100);
	student stu("Jack",90);
	print_student(stu);
	student stu2(NULL,90);
	return 0;
}

