#include "stdafx.h"
#include "SumTest.h"


CSumTest::CSumTest()
	: m_iA(0)
	, m_iB(0)
{
}


CSumTest::~CSumTest()
{
}


int CSumTest::GetSum(int A, int B)
{
	return A + B;
}
