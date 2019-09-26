#include "stdlib.h"
#include "time.h"
// MFCApplication1View.cpp : CMFCApplication1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication1View ����/�Ҹ�

CMFCApplication1View::CMFCApplication1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	Score = 0;
	IsPushed = 0;
}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication1View �׸���

void CMFCApplication1View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || !IsPushed)
		return;

	CClientDC dc(this);

	for (int i = 0; i < NUMBALL; i++) {
		if (!IsAlive[i]) continue;
		dc.Ellipse(BPoint[i].x, BPoint[i].y, BPoint[i].x + BSize[i], BPoint[i].y  + BSize[i]);
	}
	int x = m_Point.x;
	int y = m_Point.y;
	//dc.Ellipse(x - RADIUS , y - RADIUS, x + RADIUS, y + RADIUS);

	CString ScoreText;
	ScoreText.Format("Score : %d", Score);
	dc.TextOutA(500, 5, ScoreText);
	//dc.Rectangle(x, y, x + 10, y + 10);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CMFCApplication1View �μ�

BOOL CMFCApplication1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFCApplication1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFCApplication1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMFCApplication1View ����

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication1View �޽��� ó����


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_Point = point;
	IsPushed = 1;
	SetTimer(1, 5, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonUp(nFlags, point);
}


void CMFCApplication1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	//m_Point = point;
	CView::OnMouseMove(nFlags, point);
}


void CMFCApplication1View::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	CWnd* parent = this->GetParent();
	parent->GetWindowRect(&WRect);
	//printf("%d%d", WRect.Height, WRect.Width);

	for (int i = 0; i < NUMBALL; i++) {
		if (!IsAlive[i]) continue;

		BPoint[i].x = rand() % AREA + 1;
		BPoint[i].y = rand() % AREA + 1;

		BVectX[i] = rand() % 5 + 1;
		BVectY[i] = rand() % 5 + 1;

		IsAlive[i] = 1;

		BSize[i] = rand() % 30 + 21;
	}

	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


void CMFCApplication1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//m_Point.x += 10;
	//m_Point.y += 10;
	for (int i = 0; i < NUMBALL; i++) {
		if (BPoint[i].x >= AREA || BPoint[i].x < 0) BVectX[i] *= -1;
		if (BPoint[i].y >= AREA || BPoint[i].y < 0) BVectY[i] *= -1;

		BPoint[i].x += BVectX[i];
		BPoint[i].y += BVectY[i];
	}

	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMFCApplication1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	for (int i = 0; i < NUMBALL; i++) {
		if (!IsAlive[i]) continue;
		if (point.x >= BPoint[i].x && point.x <= BPoint[i].x + BSize[i] && point.y >= BPoint[i].y && point.y <= BPoint[i].y + BSize[i]) {
			Score += 1;
			IsAlive[i] = 0;
			if (Score >= 8) KillTimer(1);

			Invalidate();
			printf("Hit");
		}
	}
	CView::OnRButtonDown(nFlags, point);
}
