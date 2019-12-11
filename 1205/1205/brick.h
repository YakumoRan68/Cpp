#pragma once

class Brick : public Object {
public:
	Brick(int hardness);
	~Brick();

	bool isLive;
	int hardness;

	void OnCollide();
	void Break();
};