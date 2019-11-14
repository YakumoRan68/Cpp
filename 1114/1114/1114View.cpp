
// 1114View.cpp : CMy1114View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1114.h"
#endif

#include "1114Doc.h"
#include "1114View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1114View

IMPLEMENT_DYNCREATE(CMy1114View, CView)

BEGIN_MESSAGE_MAP(CMy1114View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy1114View ����/�Ҹ�

CMy1114View::CMy1114View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1114View::~CMy1114View()
{
}

BOOL CMy1114View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1114View �׸���

void CMy1114View::OnDraw(CDC* /*pDC*/)
{
	CMy1114Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1114View �μ�

BOOL CMy1114View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy1114View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy1114View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy1114View ����

#ifdef _DEBUG
void CMy1114View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1114View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1114Doc* CMy1114View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1114Doc)));
	return (CMy1114Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1114View �޽��� ó����
