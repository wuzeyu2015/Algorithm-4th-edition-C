// MaxPQ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HeapSort.h"

int _tmain(int argc, _TCHAR* argv[])
{
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	cout<<maxheap.size()<<endl;

	srand(time(NULL));
	for( int i = 0 ; i < 50 ; i ++ ){
		maxheap.insert( rand()%100 );
	}
	maxheap.testPrint();
	system("pause");
	return 0;
}

