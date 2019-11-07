
// T1107View.cpp : CT1107View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "T1107.h"
#endif

#include "T1107Doc.h"
#include "T1107View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CT1107View

IMPLEMENT_DYNCREATE(CT1107View, CView)

BEGIN_MESSAGE_MAP(CT1107View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(OPT_500, &CT1107View::OnOpt500)
	ON_COMMAND(OPT_700, &CT1107View::OnOpt700)
END_MESSAGE_MAP()

// CT1107View ����/�Ҹ�

CT1107View::CT1107View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CT1107View::~CT1107View()
{
}

BOOL CT1107View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CT1107View �׸���

void CT1107View::OnDraw(CDC* pDC)
{
	CT1107Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	for (int i = 0; i < NUMOBJECT; i++) {
		CPoint ObjP = ObjPoint[i];

		CBrush brush;
		brush.CreateSolidBrush(ObjColor[i]);
		pDC->SelectObject(&brush);
		pDC->Rectangle(ObjP.x, ObjP.y, ObjP.x + 50, ObjP.y + 50);
	}
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CT1107View �μ�

BOOL CT1107View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CT1107View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CT1107View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CT1107View ����

#ifdef _DEBUG
void CT1107View::AssertValid() const
{
	CView::AssertValid();
}

void CT1107View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CT1107Doc* CT1107View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CT1107Doc)));
	return (CT1107Doc*)m_pDocument;
}
#endif
// CT1107View �޽��� ó����


void CT1107View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	CView::OnLButtonDown(nFlags, point);
}

void CT1107View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽�+�� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	ObjPoint[nIDEvent].x += ObjSpeed[nIDEvent];
	Invalidate();

	if (ObjPoint[nIDEvent].x > EndLine) {
		ObjRank[nIDEvent] = rank++;
		KillTimer(nIDEvent);
	}

	CView::OnTimer(nIDEvent);
}

int num = 0;
void Shuffle() {
	srand(time(NULL) + num);
	num = num * 46781267 + 9788973;
}

double GetRandom() { // [0, 1) ������ ������ ����
	Shuffle();
	return (double)rand() / (RAND_MAX + 1.0);
}

void CT1107View::OnInitialUpdate() {
	CView::OnInitialUpdate();
	Shuffle();

	for (int i = 0; i < NUMOBJECT; i++) {
		ObjPoint[i].SetPoint(50, i * 60 + 30);
		ObjColor[i] = RGB(GetRandom() * 256, GetRandom() * 256, GetRandom() * 256);
		ObjSpeed[i] = GetRandom() * 20 + 10;
		ObjInterval[i] = GetRandom() * 120 + 30;

		SetTimer(i, ObjInterval[i], NULL);
	}
}


void CT1107View::OnOpt500()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	EndLine = 500;
	Invalidate();
}


void CT1107View::OnOpt700()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	EndLine = 700;
	Invalidate();
}
