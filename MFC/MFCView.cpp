
// MFCView.cpp : CMFCView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCView 생성/소멸

CMFCView::CMFCView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCView::~CMFCView()
{
}

BOOL CMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCView 그리기

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
	pDC->Ellipse(100, 100, 300, 300); //x, y지점에서 x2, y2를 채운 직사각형 안에서 원을 그림 */

	CPen pen; // 펜 타입 펜생성
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *Pen = pDC->SelectObject(&pen);
	pDC->MoveTo(100, 100);
	pDC->LineTo(200, 230);

	CBrush brush(RGB(0, 255, 255)); //브러시(내부를 채움)
	CBrush *Brush = pDC->SelectObject(&brush);

	pDC->Rectangle(100, 100, 300, 400);
}

void CMFCView::OnLButtonDown(UINT nFlags, CPoint point) {
	//MessageBox(_T("마우스 클릭"), _T("마우스 메세지"));
	CClientDC dc(this);
	dc.TextOut(200, 100, _T("Hello PC"), 6); //영역이 무효화 되면(다른창으로 가리는 등) 클릭하기 전까진 지워진다.

	CView::OnLButtonDown(nFlags, point);

	CPen pen; // 펜 타입 펜생성
	pen.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *Pen = dc.SelectObject(&pen);
	dc.MoveTo(100, 100);
	dc.LineTo(200, 230);

	CBrush brush(RGB(0, 255, 255)); //브러시(내부를 채움)
	CBrush *Brush = dc.SelectObject(&brush);

	dc.Rectangle(100, 100, 300, 400);
}


// CMFCView 인쇄

BOOL CMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCView 진단

#ifdef _DEBUG
void CMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCDoc* CMFCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCDoc)));
	return (CMFCDoc*)m_pDocument;
}
#endif //_DEBUG