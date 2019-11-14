
// T1107View.h : CT1107View 클래스의 인터페이스
//

#pragma once
#define NUMOBJECT 10
#define RAND_MAX 32767

class CT1107View : public CView
{
protected: // serialization에서만 만들어집니다.
	CT1107View();
	DECLARE_DYNCREATE(CT1107View)

// 특성입니다.
public:
	CT1107Doc* GetDocument() const;

	CPoint ObjPoint[NUMOBJECT];
	COLORREF ObjColor[NUMOBJECT];
	CString SRank;

	int ObjSpeed[NUMOBJECT];
	int ObjInterval[NUMOBJECT];
	int ObjRank[NUMOBJECT];
	
	int rank = 1;
	int EndLine = 500;
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
	virtual ~CT1107View();
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
//	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	afx_msg void OnOpt500();
	afx_msg void OnOpt700();
};

#ifndef _DEBUG  // T1107View.cpp의 디버그 버전
inline CT1107Doc* CT1107View::GetDocument() const
   { return reinterpret_cast<CT1107Doc*>(m_pDocument); }
#endif