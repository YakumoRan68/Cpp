
// 1010View.h : CMy1010View Ŭ������ �������̽�
//

#pragma once


class CMy1010View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1010View();
	DECLARE_DYNCREATE(CMy1010View)

// Ư���Դϴ�.
public:
	CMy1010Doc* GetDocument() const;

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
	virtual ~CMy1010View();
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
};

#ifndef _DEBUG  // 1010View.cpp�� ����� ����
inline CMy1010Doc* CMy1010View::GetDocument() const
   { return reinterpret_cast<CMy1010Doc*>(m_pDocument); }
#endif

