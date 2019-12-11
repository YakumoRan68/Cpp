#pragma once
class Object
{
public:
	Object();
	~Object();

	COLORREF color;
	CPoint center;
	CRect* HitBox;

	CRect* GetHitBox();
	void SetColor(int r, int g, int b);
};