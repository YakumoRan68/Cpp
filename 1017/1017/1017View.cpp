
// 1017View.cpp : CMy1017View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1017.h"
#endif

#include "1017Doc.h"
#include "1017View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1017View

IMPLEMENT_DYNCREATE(CMy1017View, CView)

BEGIN_MESSAGE_MAP(CMy1017View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy1017View ����/�Ҹ�

CMy1017View::CMy1017View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1017View::~CMy1017View()
{
}

BOOL CMy1017View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1017View �׸���

void CMy1017View::OnDraw(CDC* pDC)
{
	CMy1017Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect r[100];

	pDC->TextOut(100, 100, m_str);
	distance = sqrt((pt_end.x - pt_start.x) * (pt_end.x - pt_start.x));
	CString str;
	str.Format("�Ÿ� : %d", distance);

	pDC->TextOutA(pt_end.x - 5, pt_end.y - 15, str);

	pDC->MoveTo(pt_start);
	pDC->LineTo(pt_end);
	

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1017View �μ�

BOOL CMy1017View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy1017View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy1017View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy1017View ����

#ifdef _DEBUG
void CMy1017View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1017View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1017Doc* CMy1017View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1017Doc)));
	return (CMy1017Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1017View �޽��� ó����


void CMy1017View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar == VK_BACK) m_str.Delete(m_str.GetLength()-1);
	else m_str.AppendChar(nChar);

	m_str.Replace('a', 'b');

	Invalidate();
		
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy1017View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	pt_start = point;
	pressed = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMy1017View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	pt_end = point;
	pressed = false;

	CView::OnLButtonUp(nFlags, point);
}


void CMy1017View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (pressed) {
		pt_end = point;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}
