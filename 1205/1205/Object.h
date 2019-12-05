#pragma once
class Object
{
public:
	Object();
	~Object();

	COLORREF color;
	CPoint center;
	virtual CRect GetHitBox() = 0;
	void SetColor(int r, int g, int b);
};