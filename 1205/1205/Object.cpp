#include "stdafx.h"
#include "Object.h"
#include "MainFrm.h"

Object::Object() {
	SetColor(0,0,0);
}

Object::~Object() {
	delete HitBox;
}

CRect* Object::GetHitBox() {
	return HitBox;
}

void Object::SetColor(int r, int g, int b) {
	color = RGB(r,g,b);
}