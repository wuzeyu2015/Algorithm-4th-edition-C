// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "InsetionSort.h"
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "ShellSort.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n1 = 30000;
	int n2 = 10000;
	cout<<"O(n2)ÅÅÐò£º"<<endl;
	cout<<"---------------------------Select Sort-------------------------------------"<<endl;
	cout<<"Test for Random Array, size = "<<n2<<", random range [0, "<<n2<<"]"<<endl;
	int* arr = SortTestHelper::generateRandomArray(n2,0,n2);
	SortTestHelper::testSort("Select Sort",selectionSort,arr, n2);
	delete[] arr;

	cout<<"\n\r---------------------------Insert Sort-------------------------------------"<<endl;
	cout<<"Test for Random Array, size = "<<n2<<", random range [0, "<<n2<<"]"<<endl;
	arr = SortTestHelper::generateRandomArray(n2,0,n2);
	SortTestHelper::testPartitionSort("Insert Sort",__portionInsertionSort,arr, 0, n2 - 1);
	delete[] arr;
	cout<<""<<endl;

	cout<<"O(n(3/2))ÅÅÐò£º"<<endl;
	cout<<"---------------------------Shell Sort-------------------------------------"<<endl;
	cout<<"Test for Random Array, size = "<<n2<<", random range [0, "<<n2<<"]"<<endl;
	arr = SortTestHelper::generateRandomArray(n2,0,n2);
	SortTestHelper::testSort("Shell Sort",ShellSort,arr, n2);
	delete[] arr;
	cout<<""<<endl;

	cout<<"O(nlogn)ÅÅÐò£º"<<endl;
	cout<<"---------------------------Merge Sort-------------------------------------"<<endl;
	cout<<"Test for Random Array, size = "<<n1<<", random range [0, "<<n1<<"]"<<endl;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Merge Sort",MergeSort, arr, n1);
	delete[] arr;

	cout<<"Test for Random Array, size = "<<n1<<", random range [0, "<<n1<<"]"<<endl;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Merge Sort - BTU",MergeSortBTU, arr, n1);
	delete[] arr;

  	int swapTimes = 100;
	cout<<"Test for Random Nearly Ordered Array, size = "<<n1<<", swap time = "<<swapTimes<<endl;
	arr = SortTestHelper::generateNearlyOrderedArray(n1,100);
	SortTestHelper::testSort("Merge Sort",MergeSort, arr, n1);
	delete[] arr;

	cout<<"Test for Repeat Random Array, size = "<<n1<<", random range [0,10]"<<endl;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Merge Sort", MergeSort, arr, n1);
	delete[] arr;


	cout<<"\n\r---------------------------Quick Sort-------------------------------------"<<endl;
	cout<<"Test for Random Array, size = "<<n1<<", random range [0, "<<n1<<"]"<<endl;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Quick Sort", quickSort, arr, n1);
	delete[] arr;

	cout<<"Test for Random Nearly Ordered Array, size = "<<n1<<", swap time = "<<100<<endl;
	arr = SortTestHelper::generateNearlyOrderedArray(n1,100);
	SortTestHelper::testSort("Quick Sort", quickSort, arr, n1);
	delete[] arr;

	cout<<"Test for Repeated Random Array, size = "<<n1<<", random range [0,10]"<<endl;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Quick Sort", quickSort, arr, n1);
	delete[] arr;

	cout<<"Test for Repeated Random Array, size = "<<n1<<", random range [0,10]"<<endl;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Merge Sort - OPTIMIZE", quickSort2, arr, n1);
	delete[] arr;
 	system("pause");

	return 0;
}

