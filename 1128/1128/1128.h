
// 1128.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMy1128App:
// �� Ŭ������ ������ ���ؼ��� 1128.cpp�� �����Ͻʽÿ�.
//

class CMy1128App : public CWinApp
{
public:
	CMy1128App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
	afx_msg void OnBnClickedButton1();
};

extern CMy1128App theApp;