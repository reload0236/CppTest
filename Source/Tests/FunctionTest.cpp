#include <functional>
#include <iostream>

#include "FunctionTest.h"


namespace {

	int Add(int a, int b)
	{
		return a + b;
	}

	
	class CAdd
	{
	public:
		int operator()(int a, int b)
		{
			return a + b;
		}
	};

}


void FunctionTest::Run()
{
	std::function<int(int, int)> funcAdd = Add;
	std::cout << funcAdd(1, 2) << std::endl;

	funcAdd = [](int a,int b) {return a + b;};
	std::cout << funcAdd(1, 2) << std::endl;

	funcAdd = CAdd();
	std::cout << funcAdd(1, 2) << std::endl;
}
