
// T1031View.cpp : CT1031View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "T1031.h"
#endif

#include "T1031Doc.h"
#include "T1031View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CT1031View

IMPLEMENT_DYNCREATE(CT1031View, CView)

BEGIN_MESSAGE_MAP(CT1031View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_LBUTTONDOWN()
ON_WM_MOUSEMOVE()
ON_WM_CHAR()
END_MESSAGE_MAP()


CT1031View::CT1031View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CT1031View::~CT1031View()
{
}

BOOL CT1031View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CT1031View �׸���

void CT1031View::OnDraw(CDC* pDC)
{
	CT1031Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen pen, *oldPen;
	CBrush brush, *oldBrush;

	brush.CreateSolidBrush(RGB(255, 0, 0));
	//brush.CreateHatchBrush(3, RGB(255,0,0));
	oldBrush = pDC->SelectObject(&brush);
	pen.CreatePen(PS_SOLID, 3, m_PenColor);
	oldPen = pDC->SelectObject(&pen);
	//pDC->SelectObject(&pen);
	pDC->TextOutA(10, 10, color);

	//pDC->Rectangle(m_pointStart.x, m_pointStart.y, m_pointEnd.x, m_pointEnd.y);
	pDC->Polygon(PolyPoint, PolyCount);
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CT1031View �μ�

BOOL CT1031View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CT1031View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CT1031View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CT1031View ����

#ifdef _DEBUG
void CT1031View::AssertValid() const
{
	CView::AssertValid();
}

void CT1031View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CT1031Doc* CT1031View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CT1031Doc)));
	return (CT1031Doc*)m_pDocument;
}
#endif //_DEBUG


// CT1031View �޽��� ó����

void CT1031View::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_pointEnd = point;
	isClicked = false;

	CView::OnLButtonUp(nFlags, point);
}


void CT1031View::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_pointStart = point;
	isClicked = true;
	PolyPoint[GetPolyCount()] = point;

	CView::OnLButtonDown(nFlags, point);
}


void CT1031View::OnMouseMove(UINT nFlags, CPoint point)
{
	//if (isClicked) {
		m_pointEnd = point;
		Invalidate();
	//}

	CView::OnMouseMove(nFlags, point);
}


void CT1031View::OnInitialUpdate()
{
	m_PenColor = RGB(0, 0, 0);
	CView::OnInitialUpdate();
}

void CT1031View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	switch (nChar) {
		case 'r' : m_PenColor = RGB(255, 0, 0); color = "Red"; break;
		case 'g' : m_PenColor = RGB(0, 255, 0); color = "Green"; break;
		case 'b' : m_PenColor = RGB(0, 0, 255); color = "Blue"; break;
	}
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}
