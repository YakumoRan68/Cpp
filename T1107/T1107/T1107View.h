
// T1107View.h : CT1107View Ŭ������ �������̽�
//

#pragma once
#define NUMOBJECT 10
#define RAND_MAX 32767

class CT1107View : public CView
{
protected: // serialization������ ��������ϴ�.
	CT1107View();
	DECLARE_DYNCREATE(CT1107View)

// Ư���Դϴ�.
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
	virtual ~CT1107View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // T1107View.cpp�� ����� ����
inline CT1107Doc* CT1107View::GetDocument() const
   { return reinterpret_cast<CT1107Doc*>(m_pDocument); }
#endif