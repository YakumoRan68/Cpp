
// 1121View.h : CMy1121View Ŭ������ �������̽�
//

#pragma once


class CMy1121View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1121View();
	DECLARE_DYNCREATE(CMy1121View)

// Ư���Դϴ�.
public:
	CMy1121Doc* GetDocument() const;
	int m_iCurrentABC;
	CPoint m_pointCurrent;
	int m_iAlive;
	int m_interX;
	int m_interY;

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
	virtual ~CMy1121View();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

#ifndef _DEBUG  // 1121View.cpp�� ����� ����
inline CMy1121Doc* CMy1121View::GetDocument() const
   { return reinterpret_cast<CMy1121Doc*>(m_pDocument); }
#endif

