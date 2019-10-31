
// 1010View.cpp : CMy1010View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1010.h"
#include "SumTest.h"
#endif

#include "1010Doc.h"
#include "1010View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1010View

IMPLEMENT_DYNCREATE(CMy1010View, CView)

BEGIN_MESSAGE_MAP(CMy1010View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMy1010View ����/�Ҹ�

CMy1010View::CMy1010View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1010View::~CMy1010View()
{
}

BOOL CMy1010View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1010View �׸���

void CMy1010View::OnDraw(CDC* /*pDC*/)
{
	CMy1010Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1010View �μ�

BOOL CMy1010View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy1010View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy1010View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy1010View ����

#ifdef _DEBUG
void CMy1010View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1010View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1010Doc* CMy1010View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1010Doc)));
	return (CMy1010Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1010View �޽��� ó����


void CMy1010View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int a = 30, b = 40, c;

	CSumTest test;
	c = test.GetSum(a, b);
	
	CString str;
	str.Format("Test = %d", c);

	MessageBoxA(str);

	CView::OnLButtonDown(nFlags, point);
}
