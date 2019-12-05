#include "stdafx.h"
#include "Object.h"
#include "Bar.h"
#include "MainFrm.h"

Bar::Bar() {
	SetColor(0, 250, 30);	
}

Bar::~Bar() {}

void Bar::MoveTo(bool dir) {
	center.x += -STEP + STEP * 2 * dir;
}

CRect Bar::GetHitBox() {
	return CRect(center.x - WIDTH / 2, center.y - HEIGHT / 2, center.x + WIDTH / 2, center.y + HEIGHT / 2);
}