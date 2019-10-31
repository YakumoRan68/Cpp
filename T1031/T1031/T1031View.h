
// T1031View.h : CT1031View 클래스의 인터페이스
//

#pragma once

#define POLYMAX 6

class CT1031View : public CView
{
protected: // serialization에서만 만들어집니다.
	CT1031View();
	DECLARE_DYNCREATE(CT1031View)

// 특성입니다.
public:
	CT1031Doc* GetDocument() const;
	
// 작업입니다.
public:
	CPoint m_pointStart;
	CPoint m_pointEnd;
	CString color = "Black";
	COLORREF m_PenColor;
	POINT PolyPoint[POLYMAX];
	int PolyCount = 0;
	int GetPolyCount() {
		if (PolyCount >= POLYMAX) PolyCount = 0;
		return PolyCount++;
	}
	HDC HText;

	bool isClicked = false;

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
	virtual ~CT1031View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // T1031View.cpp의 디버그 버전
inline CT1031Doc* CT1031View::GetDocument() const
   { return reinterpret_cast<CT1031Doc*>(m_pDocument); }
#endif

