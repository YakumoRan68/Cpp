
// 1128Dlg.h : ��� ����
//

#pragma once


// CMy1128Dlg ��ȭ ����
class CMy1128Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CMy1128Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY1128_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
