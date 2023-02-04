#pragma once


class Runnable
{
public:
	virtual ~Runnable() = default;

	virtual void Run() = 0;
};
