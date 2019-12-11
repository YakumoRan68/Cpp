#include "stdafx.h"
#include "Object.h"
#include "Bar.h"
#include "MainFrm.h"

#define STEP 10

Bar::Bar() {
	SetColor(0, 250, 30);	
	center.SetPoint((MAP_RIGHT - MAP_LEFT) / 2, MAP_BOTTOM - 25);
	HitBox = new CRect(center.x - BAR_WIDTH / 2, center.y - BAR_HEIGHT / 2, center.x + BAR_WIDTH / 2, center.y + BAR_HEIGHT / 2);
}

Bar::~Bar() {}

void Bar::MoveTo(bool dir) {
	center.x += -STEP + STEP * 2 * dir;
	HitBox->MoveToX(center.x - BAR_WIDTH / 2);
}