
// 1010.h : 1010 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMy1010App:
// �� Ŭ������ ������ ���ؼ��� 1010.cpp�� �����Ͻʽÿ�.
//

class CMy1010App : public CWinAppEx
{
public:
	CMy1010App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy1010App theApp;
