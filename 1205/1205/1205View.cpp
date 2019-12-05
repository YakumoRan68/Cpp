
// 1205View.cpp : CMy1205View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1205.h"
#endif

#include "1205Doc.h"
#include "1205View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1205View

IMPLEMENT_DYNCREATE(CMy1205View, CView)

BEGIN_MESSAGE_MAP(CMy1205View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy1205View ����/�Ҹ�

CMy1205View::CMy1205View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1205View::~CMy1205View()
{
}

BOOL CMy1205View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1205View �׸���

void CMy1205View::OnDraw(CDC* /*pDC*/)
{
	CMy1205Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1205View �μ�

BOOL CMy1205View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy1205View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy1205View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy1205View ����

#ifdef _DEBUG
void CMy1205View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1205View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1205Doc* CMy1205View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1205Doc)));
	return (CMy1205Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1205View �޽��� ó����
