// MaxPQ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HeapSort.h"
#include "MaxPQ.h"
#include "SortTestHelper.h"

int _tmain(int argc, _TCHAR* argv[])
{
// 	MaxHeap<int> maxheap = MaxHeap<int>(100);
// 	cout<<maxheap.size()<<endl;
// 
// 	srand(time(NULL));
// 	for( int i = 0 ; i < 50 ; i ++ ){
// 		maxheap.insert( rand()%100 );
// 	}
// 	maxheap.testPrint();

	int a[10] = {1,2,3,4,5,6,7,8,9,11};
	MaxPQ<int> maxPQ(a, 10);
	vector<int> res = maxPQ.heapSort();
	for(auto it = res.begin(); it != res.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

	int b[11] = {0,10,9,8,7,6,5,4,3,2,1};
	heapSort(b, 10);
	for(auto i = 1; i < 11; i++){
		cout << b[i] << " ";
	}
	///////////////////
	HeapOpt();
	pq_Container();
	system("pause");
	return 0;
}

