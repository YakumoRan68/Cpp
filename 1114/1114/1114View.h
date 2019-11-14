
// 1114View.h : CMy1114View 클래스의 인터페이스
//

#pragma once


class CMy1114View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy1114View();
	DECLARE_DYNCREATE(CMy1114View)

// 특성입니다.
public:
	CMy1114Doc* GetDocument() const;
	CPoint m_pointCurrent;
	int m_BoomCount; //현재 출력중인 폭탄 이미지



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
	virtual ~CMy1114View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // 1114View.cpp의 디버그 버전
inline CMy1114Doc* CMy1114View::GetDocument() const
   { return reinterpret_cast<CMy1114Doc*>(m_pDocument); }
#endif

