
// MFCView.cpp : CMFCView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFC.h"
#endif

#include "MFCDoc.h"
#include "MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCView

IMPLEMENT_DYNCREATE(CMFCView, CView)

BEGIN_MESSAGE_MAP(CMFCView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFCView ����/�Ҹ�

CMFCView::CMFCView()
	: m_str(_T(""))
	, p1(0)
	, p2(0)
	, p3(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	rt.left = 100;
	rt.top = 100;
	rt.right = 300;
	rt.bottom = 200;
}

CMFCView::~CMFCView()
{
	
}

BOOL CMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFCView �μ�

BOOL CMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMFCView ����

#ifdef _DEBUG
void CMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDoc* CMFCView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDoc)));
	return (CMFCDoc*)m_pDocument;
}
#endif //_DEBUG

void CMFCView::OnDraw(CDC* pDC)
{
	CMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	/*
	pDC->TextOut(100, 100, _T("Hello PC"), 6);
	pDC->MoveTo(100, 100);
	pDC->LineTo(200, 230);
	pDC->Rectangle(100, 100, 300, 400);
	pDC->Ellipse(100, 100, 300, 300); //x, y�������� x2, y2�� ä�� ���簢�� �ȿ��� ���� �׸�

	CPen pen; // �� Ÿ�� �����
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *Pen = pDC->SelectObject(&pen);
	pDC->MoveTo(100, 100);
	pDC->LineTo(200, 230);

	CBrush brush(RGB(0, 255, 255)); //�귯��(���θ� ä��)
	CBrush *Brush = pDC->SelectObject(&brush);

	pDC->Rectangle(100, 100, 300, 400); */

	pDC->DrawText(L"MFC���α׷��� ����", &rt, DT_CENTER | DT_VCENTER);
	pDC->TextOutW(0, 0, m_str, m_str.GetLength());

	pDC->MoveTo(p1);
	pDC->LineTo(p2.x, p2.y);
}

void CMFCView::OnLButtonDown(UINT nFlags, CPoint point) {
	//MessageBox(_T("���콺 Ŭ��"), _T("���콺 �޼���"));
	CClientDC dc(this);
	/*
	dc.TextOut(200, 100, _T("Hello PC"), 6); //������ ��ȿȭ �Ǹ�(�ٸ�â���� ������ ��) Ŭ���ϱ� ������ ��������.

	CView::OnLButtonDown(nFlags, point);

	CPen pen; // �� Ÿ�� �����
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *Pen = dc.SelectObject(&pen);
	dc.MoveTo(100, 100);
	dc.LineTo(200, 230);

	CBrush brush(RGB(0, 255, 255)); //�귯��(���θ� ä��)
	CBrush *Brush = dc.SelectObject(&brush);

	dc.Rectangle(100, 100, 300, 400);
	*/

	p1 = point;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CMFCView::OnLButtonUp(UINT nFlags, CPoint point)
{

	p2.x = point.x;
	p2.y = point.y;
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CMFCView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nChar == VK_BACK) m_str.Delete(m_str.GetLength() - 1);
	else m_str.AppendChar(nChar);
	Invalidate(); // OnDraw�� �ٽ� ���۽�Ŵ
	
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CMFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nFlags & MK_LBUTTON) { //���콺�� ������ ���� ��
		p2 = point;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}
