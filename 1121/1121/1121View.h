
// 1121View.h : CMy1121View 클래스의 인터페이스
//

#pragma once


class CMy1121View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy1121View();
	DECLARE_DYNCREATE(CMy1121View)

// 특성입니다.
public:
	CMy1121Doc* GetDocument() const;
	int m_iCurrentABC;
	CPoint m_pointCurrent;
	int m_iAlive;
	int m_interX;
	int m_interY;

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
	virtual ~CMy1121View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // 1121View.cpp의 디버그 버전
inline CMy1121Doc* CMy1121View::GetDocument() const
   { return reinterpret_cast<CMy1121Doc*>(m_pDocument); }
#endif

