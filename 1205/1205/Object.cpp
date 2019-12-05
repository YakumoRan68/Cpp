#include "stdafx.h"
#include "Object.h"
#include "MainFrm.h"

Object::Object() {
	SetColor(0,0,0);
}

Object::~Object() {}

void Object::SetColor(int r, int g, int b) {
	color = RGB(r,g,b);
}