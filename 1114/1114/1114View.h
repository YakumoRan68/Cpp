
// 1114View.h : CMy1114View Ŭ������ �������̽�
//

#pragma once


class CMy1114View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1114View();
	DECLARE_DYNCREATE(CMy1114View)

// Ư���Դϴ�.
public:
	CMy1114Doc* GetDocument() const;
	CPoint m_pointCurrent;
	int m_BoomCount; //���� ������� ��ź �̹���



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
	virtual ~CMy1114View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // 1114View.cpp�� ����� ����
inline CMy1114Doc* CMy1114View::GetDocument() const
   { return reinterpret_cast<CMy1114Doc*>(m_pDocument); }
#endif

