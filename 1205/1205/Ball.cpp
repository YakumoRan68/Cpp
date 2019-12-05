#include "stdafx.h"
#include "Object.h"
#include "ball.h"
#include "MainFrm.h"

Ball::Ball() {
	center.SetPoint(250, 50);
	VectX = 5;
	VectY = 5;
}

Ball::~Ball() {}

CRect Ball::GetHitBox() {
	return CRect(center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}

void Ball::OnCollide(short flag) {
	VectY *= pow(-1, flag % 2);
	VectX *= pow(-1, flag / 2);
}

void Ball::OnTick() {
	center.x += VectX;
	center.y += VectY;
}