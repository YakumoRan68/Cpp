
// BallGameView.h: CBallGameView 클래스의 인터페이스
//

#pragma once
#define RADIUS 30
#define AREA 500
#define MAXNUMBALL 50

class CBallGameView : public CView
{
protected: // serialization에서만 만들어집니다.
	CBallGameView() noexcept;
	DECLARE_DYNCREATE(CBallGameView)

// 특성입니다.
public:
	CBallGameDoc* GetDocument() const;
	int IsPushed = 0;
	int Score = 0;
	int Level = 1;
	int NumBall = 10;
	int LevelTimer = 3;

	CString Intro;
	CPoint m_Point;
	CRect WRect;
	CPoint BPoint[MAXNUMBALL];

	int BSize[MAXNUMBALL];
	int BVectX[MAXNUMBALL];
	int BVectY[MAXNUMBALL];
	int IsAlive[MAXNUMBALL];
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CBallGameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	void LevelScailing();
};

#ifndef _DEBUG  // BallGameView.cpp의 디버그 버전
inline CBallGameDoc* CBallGameView::GetDocument() const
   { return reinterpret_cast<CBallGameDoc*>(m_pDocument); }
#endif

