
// 1017View.h : CMy1017View 클래스의 인터페이스
//

#pragma once


class CMy1017View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMy1017View();
	DECLARE_DYNCREATE(CMy1017View)

// 특성입니다.
public:
	CMy1017Doc* GetDocument() const;

// 작업입니다.
public:
	CString m_str;
	bool pressed = false;
	int distance = 0;
	CPoint pt_start;
	CPoint pt_end;

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
	virtual ~CMy1017View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 1017View.cpp의 디버그 버전
inline CMy1017Doc* CMy1017View::GetDocument() const
   { return reinterpret_cast<CMy1017Doc*>(m_pDocument); }
#endif

