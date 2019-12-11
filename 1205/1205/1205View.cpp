
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

void CMy1205View::Shuffle() {
	srand((unsigned int)(time(NULL)) + seed);
	seed = seed * 14239102 + 23058298;
}


double CMy1205View::GetRandom() {
	Shuffle();
	return (double)rand() / (RAND_MAX + 1.0);
}

CMy1205View::CMy1205View()
{
	score = 0;
	for (int i = 0; i < BRICKS_ROW; i++) {
		for (int j = 0; j < BRICKS_COL; j++) {
			Brick *brick = new Brick((int)(GetRandom() * 3));
			brick->center.SetPoint(75 + (BRICK_WIDTH + 10) * j, 40 + (BRICK_HEIGHT + 5) * i);
			brick->HitBox->OffsetRect(brick->center);
			bricks[i * BRICKS_COL + j] = brick;
		}
	}

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

	CDC mdc;
	mdc.CreateCompatibleDC(pDC);

	CPen pen, *oldpen;

	pen.CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	oldpen = pDC->SelectObject(&pen);

	pDC->MoveTo(MAP_RIGHT, MAP_TOP);
	pDC->LineTo(MAP_RIGHT, MAP_BOTTOM);

	pDC->MoveTo(MAP_LEFT, MAP_BOTTOM);
	pDC->LineTo(MAP_RIGHT, MAP_BOTTOM);

	CString txt, life;
	txt.Format(L"Score : %d", score);
	life.Format(L"Lives : %d", lives);
	
	pDC->TextOut(MAP_RIGHT - 80, 5, txt);
	pDC->TextOut(MAP_LEFT, 5, life);


	for (int i = 0; i < BRICKS_ROW; i++) {
		for (int j = 0; j < BRICKS_COL; j++) {
			int index = i * BRICKS_COL + j;
			Brick *brick = bricks[index];
			if (!brick->isLive) continue;
			CRect *BrickBox = bricks[index]->GetHitBox();
			CPoint BrickP1 = BrickBox->TopLeft();
			CPoint BrickP2 = BrickBox->BottomRight();

			CBitmap bit;
			bit.LoadBitmapW(BRICK_1 + brick->hardness);
			mdc.SelectObject(&bit);
			pDC->BitBlt(BrickP1.x, BrickP1.y, BRICK_WIDTH, BRICK_HEIGHT, &mdc, 0, 0, SRCCOPY); //이미지 크기 : (200, 138)
		}
	}

	pDC->Ellipse(ball.GetHitBox());
	pDC->Rectangle(bar.GetHitBox());
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

	if (bar.center.x > MAP_RIGHT - BAR_WIDTH / 2) bar.center = MAP_RIGHT - BAR_WIDTH / 2;
	if (bar.center.x < MAP_LEFT + BAR_WIDTH / 2) bar.center = MAP_LEFT + BAR_WIDTH / 2;
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMy1205View::OnTimer(UINT_PTR nIDEvent)
{
	ball.OnTick();
	seed++;
	
	CRect BarBox = bar.GetHitBox();
	CPoint BarP1 = BarBox.TopLeft();
	CPoint BarP2 = BarBox.BottomRight();

	CRect BallBox = ball.GetHitBox();
	CPoint BallP1 = BallBox.TopLeft();
	CPoint BallP2 = BallBox.BottomRight();

	short flag = 0; //충돌 플래그

	if (BallP1.x < MAP_LEFT || BallP2.x > MAP_RIGHT) {
		flag = flag | 2;
	}

	if (BallP1.y < MAP_TOP || (BarP1.y < BallP2.y && (BarP1.x <= BallP2.x && BarP2.x >= BallP1.x) ) ) {
		flag = flag | 1;
	}

	if (BallP2.y > MAP_BOTTOM) { 
		if (--lives <= 0) {
			KillTimer(1);
			MessageBox(L"Game Over!");
		}

		ball.InitPosition();
	}
	
	for (int i = 0; i < NUM_BRICKS; i++) { 
		CRect BrickBox = bricks[i]->GetHitBox(); //Todo : GetNearestBrick() 구현

		if (BrickBox.IntersectRect(BallBox, BrickBox) && bricks[i]->isLive) {
			CPoint BrickP1 = BrickBox.TopLeft();
			CPoint BrickP2 = BrickBox.BottomRight();

			if (BallP2.y > BrickP1.y || BallP1.y < BrickP2.y) {
				flag = flag | 1;
			}

			score += 100;
			bricks[i]->OnCollide();
		}
	}

	ball.OnCollide(flag);

	Invalidate();

	CView::OnTimer(nIDEvent);
}

void CMy1205View::OnInitialUpdate() {
	CView::OnInitialUpdate();
	Shuffle();

	SetTimer(1, 10, NULL);
}
