// PQ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MaxPQ.h"
#include "MinPQ.h"

int main()
{
	//MinPQ<int>::testMinPQ();
	cout << "================================" << endl;
	MaxPQ<int>::testMaxPQ();
	system("pause");
	return 0;
}

