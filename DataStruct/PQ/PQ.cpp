// PQ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MaxPQ.h"
#include "MinPQ.h"

int main()
{
	MinPQ<int>* pObj = new MinPQ<int>(20);
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
		pObj->insert(rand() % 200);

	vector<int> arr;
	for (int i = 0; i < 20; i++) {
		arr.push_back(pObj->delMin());
	}
	for (auto n : arr) {
		cout << n << " ";
	}
	system("pause");
	return 0;
}

