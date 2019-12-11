#include "stdafx.h"
#include "Object.h"
#include "Brick.h"
#include "MainFrm.h"

Brick::Brick(int Hardness) {
	isLive = true;
	hardness = Hardness;
	HitBox = new CRect(center.x - BRICK_WIDTH / 2, center.y - BRICK_HEIGHT / 2, center.x + BRICK_WIDTH / 2, center.y + BRICK_HEIGHT / 2);
}

Brick::~Brick() {}

void Brick::Break() {
	isLive = false;
}

void Brick::OnCollide() {
	if (--hardness < 0 && isLive) Break();
}