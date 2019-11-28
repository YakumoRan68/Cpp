
// 1128Dlg.h : 헤더 파일
//

#pragma once


// CMy1128Dlg 대화 상자
class CMy1128Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMy1128Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY1128_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strEditTest;
	afx_msg void OnBnClickedButton1();
	CString m_strEditTest2;
	CString m_strEditTest3;
	afx_msg void OnEnChangeEdit1();
	afx_msg void UpdateText();
	afx_msg void OnEnChangeEdit2();
};
