#include "stdafx.h"
#include "Object.h"
#include "ball.h"
#include "MainFrm.h"

Ball::Ball() {
	radius = BALL_RADIUS;
	InitPosition();
	HitBox = new CRect(center.x - radius, center.y - radius, center.x + radius, center.y + radius);
}

Ball::~Ball() {}

void Ball::InitPosition() {
	center.SetPoint((MAP_RIGHT - MAP_LEFT) / 2, MAP_BOTTOM - 100);
	VectX = BALL_SPEED;
	VectY = -BALL_SPEED;
}

void Ball::OnCollide(short flag) {
	VectY *= (int)pow(-1, flag % 2);
	VectX *= (int)pow(-1, flag / 2);
}

void Ball::OnStopTick() {
	VectX = 0;
	VectY = 0;
}

void Ball::OnTick() {
	center.x += VectX;
	center.y += VectY;
	HitBox->MoveToXY(center);
}