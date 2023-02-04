#include <functional>
#include <iostream>

#include "RightReferenceTest.h"


namespace {
	class TestClass
	{
	public:
		TestClass()
		{
		}


		TestClass(int aA) : a(aA)
		{}


		TestClass(TestClass& anotherClass) : a(anotherClass.a)
		{
			std::cout << "TestClass copy constructor called" << std::endl;
		}


		TestClass(TestClass&& anotherClass) noexcept : a(anotherClass.a)
		{
			std::cout << "TestClass move constructor called" << std::endl;
		}


		operator int()
		{
			return a;
		}
	

	private:
		int a = 1;
	};

}


void RightReferenceTest::Run()
{
	TestClass tc1(1);
	TestClass tc2(tc1);
	TestClass tc3( std::move(tc2) );	// don't use tc2 any more
}
