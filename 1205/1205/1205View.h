
// 1205View.h : CMy1205View Ŭ������ �������̽�
//

#pragma once
#include "Object.h"
#include "Ball.h"
#include "Bar.h"
#include "Brick.h"

class CMy1205View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1205View();
	DECLARE_DYNCREATE(CMy1205View)

// Ư���Դϴ�.
public:
	CMy1205Doc* GetDocument() const;
	
	Ball ball;
	Bar bar; //is you

	int score;
	int lives = MAX_LIVES;
	int seed;

	Brick *bricks[NUM_BRICKS];

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMy1205View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	void Shuffle();
	double GetRandom();
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // 1205View.cpp�� ����� ����
inline CMy1205Doc* CMy1205View::GetDocument() const
   { return reinterpret_cast<CMy1205Doc*>(m_pDocument); }
#endif

