
// 1205View.cpp : CMy1205View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "1205.h"
#endif

#include "1205Doc.h"
#include "1205View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1205View

IMPLEMENT_DYNCREATE(CMy1205View, CView)

BEGIN_MESSAGE_MAP(CMy1205View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMy1205View 생성/소멸

CMy1205View::CMy1205View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1205View::~CMy1205View()
{
}

BOOL CMy1205View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy1205View 그리기

void CMy1205View::OnDraw(CDC* pDC)
{
	CMy1205Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy1205View 인쇄

BOOL CMy1205View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy1205View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy1205View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy1205View 진단

#ifdef _DEBUG
void CMy1205View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1205View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1205Doc* CMy1205View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1205Doc)));
	return (CMy1205Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1205View 메시지 처리기


void CMy1205View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar) {
	case VK_LEFT:
		bar.MoveTo(LEFT);
		break;
	case VK_RIGHT:
		bar.MoveTo(RIGHT);
		break;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy1205View::OnTimer(UINT_PTR nIDEvent)
{
	ball.OnTick();
	
	CRect BallBox = ball.GetHitBox();
	CPoint BallP1 = BallBox.TopLeft();
	CPoint BallP2 = BallBox.BottomRight();

	short flag = 0;

	if (BallP1.x < MAP_LEFT || BallP2.x > MAP_RIGHT) {
		flag = flag | 2;
	}

	if (BallP1.y < MAP_TOP) {
		flag = flag | 1;
	}


	CView::OnTimer(nIDEvent);
}
