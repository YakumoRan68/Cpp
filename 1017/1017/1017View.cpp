
// 1017View.cpp : CMy1017View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "1017.h"
#endif

#include "1017Doc.h"
#include "1017View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy1017View

IMPLEMENT_DYNCREATE(CMy1017View, CView)

BEGIN_MESSAGE_MAP(CMy1017View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMy1017View 생성/소멸

CMy1017View::CMy1017View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMy1017View::~CMy1017View()
{
}

BOOL CMy1017View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMy1017View 그리기

void CMy1017View::OnDraw(CDC* pDC)
{
	CMy1017Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect r[100];

	pDC->TextOut(100, 100, m_str);
	distance = sqrt((pt_end.x - pt_start.x) * (pt_end.x - pt_start.x));
	CString str;
	str.Format("거리 : %d", distance);

	pDC->TextOutA(pt_end.x - 5, pt_end.y - 15, str);

	pDC->MoveTo(pt_start);
	pDC->LineTo(pt_end);
	

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMy1017View 인쇄

BOOL CMy1017View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy1017View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy1017View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMy1017View 진단

#ifdef _DEBUG
void CMy1017View::AssertValid() const
{
	CView::AssertValid();
}

void CMy1017View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy1017Doc* CMy1017View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy1017Doc)));
	return (CMy1017Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy1017View 메시지 처리기


void CMy1017View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_BACK) m_str.Delete(m_str.GetLength()-1);
	else m_str.AppendChar(nChar);

	m_str.Replace('a', 'b');

	Invalidate();
		
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMy1017View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	pt_start = point;
	pressed = true;

	CView::OnLButtonDown(nFlags, point);
}


void CMy1017View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	pt_end = point;
	pressed = false;

	CView::OnLButtonUp(nFlags, point);
}


void CMy1017View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pressed) {
		pt_end = point;
		Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}
