
// T1107.h : T1107 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CT1107App:
// �� Ŭ������ ������ ���ؼ��� T1107.cpp�� �����Ͻʽÿ�.
//

class CT1107App : public CWinApp
{
public:
	CT1107App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CT1107App theApp;
