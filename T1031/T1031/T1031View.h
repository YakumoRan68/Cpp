
// T1031View.h : CT1031View Ŭ������ �������̽�
//

#pragma once


class CT1031View : public CView
{
protected: // serialization������ ��������ϴ�.
	CT1031View();
	DECLARE_DYNCREATE(CT1031View)

// Ư���Դϴ�.
public:
	CT1031Doc* GetDocument() const;
	
// �۾��Դϴ�.
public:
	CPoint m_pointStart;
	CPoint m_pointEnd;
	bool isClicked = false;
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
	virtual ~CT1031View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
//	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // T1031View.cpp�� ����� ����
inline CT1031Doc* CT1031View::GetDocument() const
   { return reinterpret_cast<CT1031Doc*>(m_pDocument); }
#endif

