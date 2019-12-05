#pragma once

#define LEFT 0
#define RIGHT 1
#define WIDTH 50
#define HEIGHT 8
#define STEP 10

class Bar : public Object
{
public:
	Bar();
	~Bar();

	CRect GetHitBox();
	void MoveTo(bool dir);
};