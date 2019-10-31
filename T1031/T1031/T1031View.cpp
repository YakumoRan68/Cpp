
// T1031View.cpp : CT1031View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
//	ON_WM_LBUTTONDBLCLK()
ON_WM_LBUTTONDOWN()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


CT1031View::CT1031View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CT1031View::~CT1031View()
{
}

BOOL CT1031View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CT1031View 그리기

void CT1031View::OnDraw(CDC* pDC)
{
	CT1031Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->Rectangle(m_pointStart.x, m_pointStart.y, m_pointEnd.x, m_pointEnd.y);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CT1031View 인쇄

BOOL CT1031View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CT1031View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CT1031View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CT1031View 진단

#ifdef _DEBUG
void CT1031View::AssertValid() const
{
	CView::AssertValid();
}

void CT1031View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CT1031Doc* CT1031View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CT1031Doc)));
	return (CT1031Doc*)m_pDocument;
}
#endif //_DEBUG


// CT1031View 메시지 처리기


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

	CView::OnLButtonDown(nFlags, point);
}


void CT1031View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (isClicked) {
		m_pointEnd = point;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}


void CT1031View::OnInitialUpdate()
{
	CView::OnInitialUpdate();


}
