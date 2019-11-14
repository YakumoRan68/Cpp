
// 1114View.cpp : CMy1114View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy1114View 생성/소멸

CMy1114View::CMy1114View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1114View::~CMy1114View()
{
}

BOOL CMy1114View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy1114View 그리기

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
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy1114View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy1114View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy1114View 진단

#ifdef _DEBUG
void CMy1114View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1114View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1114Doc* CMy1114View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1114Doc)));
	return (CMy1114Doc*)m_pDocument;
}
#endif //_DEBUG


void CMy1114View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pointCurrent = point;
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


BOOL CMy1114View::OnEraseBkgnd(CDC* pDC) //화면을 지우는 부분을 담당
{
	//return false;
	return CView::OnEraseBkgnd(pDC);
}


void CMy1114View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_pointCurrent = point;
	m_BoomCount = 0;

	SetTimer(1, 10, NULL);
	CView::OnLButtonDown(nFlags, point);
}


void CMy1114View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
