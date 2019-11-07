
// T1107View.cpp : CT1107View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(OPT_500, &CT1107View::OnOpt500)
	ON_COMMAND(OPT_700, &CT1107View::OnOpt700)
END_MESSAGE_MAP()

// CT1107View 생성/소멸

CT1107View::CT1107View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CT1107View::~CT1107View()
{
}

BOOL CT1107View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CT1107View 그리기

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
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CT1107View 인쇄

BOOL CT1107View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CT1107View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CT1107View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CT1107View 진단

#ifdef _DEBUG
void CT1107View::AssertValid() const
{
	CView::AssertValid();
}

void CT1107View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CT1107Doc* CT1107View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CT1107Doc)));
	return (CT1107Doc*)m_pDocument;
}
#endif
// CT1107View 메시지 처리기


void CT1107View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CView::OnLButtonDown(nFlags, point);
}

void CT1107View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시+지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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

double GetRandom() { // [0, 1) 범위의 난수를 생성
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
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	EndLine = 500;
	Invalidate();
}


void CT1107View::OnOpt700()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	EndLine = 700;
	Invalidate();
}
