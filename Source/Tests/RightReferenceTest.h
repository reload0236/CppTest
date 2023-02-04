#pragma once

#include "../Runnable.h"

class RightReferenceTest : public Runnable
{
public:
	RightReferenceTest() = default;

	void Run() override;
};
