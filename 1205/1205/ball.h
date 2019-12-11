#pragma once

class Ball : public Object
{
public:
	Ball();
	~Ball();
	int radius;
	int VectX, VectY;

	void InitPosition();
	void OnCollide(short flag);
	void OnTick();
	void OnStopTick();
};