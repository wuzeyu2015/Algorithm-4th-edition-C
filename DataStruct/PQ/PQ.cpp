// PQ.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MaxPQ.h"

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,11 };
	MaxPQ<int> maxPQ(a, 10);
	vector<int> res = maxPQ.heapSort();
	for (auto it = res.begin(); it != res.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	int b[11] = { 0,10,9,8,7,6,5,4,3,2,1 };
	MaxPQ<int>::heapSort(b, 10);
	for (auto i = 1; i < 11; i++) {
		cout << b[i] << " ";
	}
	///////////////////
	MaxPQ<int>::HeapOpt();
	MaxPQ<int>::pq_Container();
	system("pause");
	return 0;
}

