
// T1031.h : T1031 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CT1031App:
// �� Ŭ������ ������ ���ؼ��� T1031.cpp�� �����Ͻʽÿ�.
//

class CT1031App : public CWinApp
{
public:
	CT1031App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CT1031App theApp;
