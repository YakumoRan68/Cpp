#pragma once

#define LEFT 0
#define RIGHT 1

class Bar : public Object
{
public:
	Bar();
	~Bar();

	void MoveTo(bool dir);
};