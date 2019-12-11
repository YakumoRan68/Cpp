
// 1121View.cpp : CMy1121View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "1121.h"
#endif

#include "1121Doc.h"
#include "1121View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1121View

IMPLEMENT_DYNCREATE(CMy1121View, CView)

BEGIN_MESSAGE_MAP(CMy1121View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMy1121View ����/�Ҹ�

CMy1121View::CMy1121View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMy1121View::~CMy1121View()
{
}

BOOL CMy1121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMy1121View �׸���

void CMy1121View::OnDraw(CDC* pDC)
{
	CMy1121Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPaintDC dc(this);

	Graphics graphics(pDC->m_hDC);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Image image(L"background.jpg"); 
	Image imageABC(L"abc.png");
	                            
	//graphics.DrawImage(&image, 0, 0, image.GetWidth(), image.GetHeight());
	//graphics.DrawImage(&imageABC, 0, 0, imageABC.GetWidth(), imageABC.GetHeight());

	int x = m_iCurrentABC % 15, y = m_iCurrentABC / 15;

	graphics.DrawImage(&imageABC, m_pointCurrent.x, m_pointCurrent.y, x*94, y*94, 94, 94, UnitPixel);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMy1121View �μ�

BOOL CMy1121View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMy1121View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMy1121View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMy1121View ����

#ifdef _DEBUG
void CMy1121View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1121View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1121Doc* CMy1121View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1121Doc)));
	return (CMy1121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1121View �޽��� ó����


void CMy1121View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	m_iCurrentABC = rand() * 20;
	m_pointCurrent = CPoint(0,0);
	m_iAlive = 1;

	SetTimer(1, 50, NULL);

	CView::OnLButtonDown(nFlags, point);
}


void CMy1121View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_pointCurrent.x += m_interX;
	m_pointCurrent.y += m_interY;

	if (m_pointCurrent.x < 0 || m_pointCurrent.x > 790) m_interX *= -1;
	if (m_pointCurrent.y < 0 || m_pointCurrent.y > 490) m_interY *= -1;

	Invalidate();

	CView::OnTimer(nIDEvent);
}


void CMy1121View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_iCurrentABC = rand() * 20;
	m_pointCurrent = CPoint(0,0);
	m_iAlive = 0;
	m_interX = 5;
	m_interY = 5;
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


BOOL CMy1121View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	return false;
	//return CView::OnEraseBkgnd(pDC);
}
