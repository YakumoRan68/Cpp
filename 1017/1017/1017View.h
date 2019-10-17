
// 1017View.h : CMy1017View Ŭ������ �������̽�
//

#pragma once


class CMy1017View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMy1017View();
	DECLARE_DYNCREATE(CMy1017View)

// Ư���Դϴ�.
public:
	CMy1017Doc* GetDocument() const;

// �۾��Դϴ�.
public:
	CString m_str;
	bool pressed = false;
	int distance = 0;
	CPoint pt_start;
	CPoint pt_end;

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
	virtual ~CMy1017View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 1017View.cpp�� ����� ����
inline CMy1017Doc* CMy1017View::GetDocument() const
   { return reinterpret_cast<CMy1017Doc*>(m_pDocument); }
#endif

