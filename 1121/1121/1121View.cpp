
// 1121View.cpp : CMy1121View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMy1121View 생성/소멸

CMy1121View::CMy1121View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1121View::~CMy1121View()
{
}

BOOL CMy1121View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy1121View 그리기

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

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy1121View 인쇄

BOOL CMy1121View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy1121View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy1121View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy1121View 진단

#ifdef _DEBUG
void CMy1121View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1121View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1121Doc* CMy1121View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1121Doc)));
	return (CMy1121Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1121View 메시지 처리기


void CMy1121View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_iCurrentABC = rand() * 20;
	m_pointCurrent = CPoint(0,0);
	m_iAlive = 1;

	SetTimer(1, 50, NULL);

	CView::OnLButtonDown(nFlags, point);
}


void CMy1121View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


BOOL CMy1121View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return false;
	//return CView::OnEraseBkgnd(pDC);
}
