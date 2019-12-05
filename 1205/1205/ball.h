#pragma once
#define RADIUS 7;

class Ball : public Object
{
public:
	Ball();
	~Ball();
	int radius = RADIUS;
	int VectX, VectY;

	CRect GetHitBox();
	void OnCollide(short flag);
	void OnTick();
};