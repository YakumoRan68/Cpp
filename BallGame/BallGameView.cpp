
// BallGameView.cpp: CBallGameView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "BallGame.h"
#endif

#include "BallGameDoc.h"
#include "BallGameView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBallGameView

IMPLEMENT_DYNCREATE(CBallGameView, CView)

BEGIN_MESSAGE_MAP(CBallGameView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CBallGameView 생성/소멸

CBallGameView::CBallGameView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

CBallGameView::~CBallGameView()
{
}

BOOL CBallGameView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBallGameView 그리기

void CBallGameView::OnDraw(CDC* /*pDC*/)
{
	CBallGameDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CClientDC dc(this);

	for (int i = 0; i < NumBall; i++) {
		if (!IsAlive[i]) continue;
		dc.Ellipse(BPoint[i].x, BPoint[i].y, BPoint[i].x + BSize[i], BPoint[i].y + BSize[i]);
	}

	CString ScoreText;
	ScoreText.Format("Level : %d  Score : %d", Level, Score);
	dc.TextOutA(500, 5, ScoreText);

	if (!IsPushed) dc.TextOutA(200, 250, Intro);
}


// CBallGameView 인쇄

BOOL CBallGameView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBallGameView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBallGameView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CBallGameView 진단

#ifdef _DEBUG
void CBallGameView::AssertValid() const
{
	CView::AssertValid();
}

void CBallGameView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBallGameDoc* CBallGameView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBallGameDoc)));
	return (CBallGameDoc*)m_pDocument;
}
#endif //_DEBUG


void CBallGameView::LevelScailing() {
	NumBall = 5 + Level * 5;

	for (int i = 0; i < NumBall; i++) {
		BPoint[i].x = rand() % AREA + 1;
		BPoint[i].y = rand() % AREA + 1;

		BVectX[i] = rand() % (3 + Level) + (1 + 0.5 * Level);
		BVectY[i] = rand() % (3 + Level) + (1 + 0.5 * Level);

		IsAlive[i] = 1;

		BSize[i] = rand() % (50 - Level * 4) + (21 - Level);
	}
}


void CBallGameView::OnLButtonDown(UINT nFlags, CPoint point) {
	if (!IsPushed) return;

	for (int i = 0; i < NumBall; i++) {
		if (!IsAlive[i]) continue;
		if (point.x >= BPoint[i].x && point.x <= BPoint[i].x + BSize[i] && point.y >= BPoint[i].y && point.y <= BPoint[i].y + BSize[i]) {
			Score += Level;
			IsAlive[i] = 0;
			if (Score >= NumBall * Level) {
				IsPushed = 0;
				LevelTimer = 2;
				Intro.Format("Start In... %d", 3);
				SetTimer(2, 1000, NULL);
			}

			Invalidate();
		}
	}
	CView::OnLButtonDown(nFlags, point);
}

void CBallGameView::OnInitialUpdate() {
	CView::OnInitialUpdate();

	Intro.Format("아무키나 눌러 시작하세요.");

	CWnd* parent = this->GetParent();
	parent->GetWindowRect(&WRect);

	LevelScailing();
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}

void CBallGameView::OnTimer(UINT_PTR nIDEvent) {
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	
	if (nIDEvent == 2) {
		if (LevelTimer > 0) {
			Intro.Format("Start In... %d", LevelTimer);
			LevelTimer -= 1;
		} else {
			Score = 0;
			IsPushed = 1;
			Level++;
			LevelScailing();
			KillTimer(2);
		}
		
	} else {
		for (int i = 0; i < NumBall; i++) {
			if (BPoint[i].x >= AREA || BPoint[i].x < 0) BVectX[i] *= -1;
			if (BPoint[i].y >= AREA || BPoint[i].y < 0) BVectY[i] *= -1;

			BPoint[i].x += BVectX[i];
			BPoint[i].y += BVectY[i];
		}
	}

	Invalidate();
	CView::OnTimer(nIDEvent);
}


void CBallGameView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) {
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	IsPushed = 1;
	SetTimer(1, 5, NULL);

	CView::OnChar(nChar, nRepCnt, nFlags);
}