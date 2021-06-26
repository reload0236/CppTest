#pragma once

#include <iostream>

#include "Test.h"


class DebugSymbolTest : public Test
{
public:
	inline void Run() override
	{
		std::cout << __func__ << std::endl;
		std::cout << __FILE__ << std::endl;
		std::cout << __LINE__ << std::endl;
		std::cout << __TIME__ << std::endl;
		std::cout << __DATE__ << std::endl;
	}
};