
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
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
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

void CMy1114View::OnDraw(CDC* pDC)
{
	CMy1114Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CDC mdc;
	mdc.CreateCompatibleDC(pDC);

	CBitmap bit, bit2;
	bit.LoadBitmap(IDB_BITMAP_SAMPLE);
	
	mdc.SelectObject(&bit);
	pDC->BitBlt(0,0,1024,768,&mdc,100,0, SRCCOPY);
	//pDC->StretchBlt(m_pointCurrent.x - 80, m_pointCurrent.y - 80, 160, 160, &mdc, m_pointCurrent.x - 20, m_pointCurrent.y - 20, 40, 40, SRCCOPY);
	
	bit2.LoadBitmap(IDB_BITMAP_BOOM);
	mdc.SelectObject(&bit2);
	pDC->BitBlt(m_pointCurrent.x - 50, m_pointCurrent.y - 50, 100, 100, &mdc, (m_BoomCount % 8) * 100 , (m_BoomCount / 8) * 100, SRCCOPY);
}



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


void CMy1114View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_pointCurrent = point;
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


BOOL CMy1114View::OnEraseBkgnd(CDC* pDC) //ȭ���� ����� �κ��� ���
{
	//return false;
	return CView::OnEraseBkgnd(pDC);
}


void CMy1114View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_pointCurrent = point;
	m_BoomCount = 0;

	SetTimer(1, 10, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CMy1114View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_BoomCount++ > 40) {
		m_BoomCount = 0;
		KillTimer(1);
	}

	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CMy1114View::OnInitialUpdate()
{
	m_BoomCount = 0;
	CView::OnInitialUpdate();
}
