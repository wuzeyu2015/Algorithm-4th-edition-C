// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SelectionSort.h"
#include "QuickSort.h"
#include "InsetionSort.h"
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "ShellSort.h"
#include "HeapSort.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n1 = 30000;
	int n2 = 10000;

	cout<<"Test for Random Array, size = "<<n2<<", random range [0, "<<n2<<"]"<<endl;
	int* arr = SortTestHelper::generateRandomArray(n2,0,n2);
	SortTestHelper::testSort("Select Sort",selectionSort,arr, n2);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n2,0,n2);
	SortTestHelper::testPartitionSort("Insert Sort",__portionInsertionSort,arr, 0, n2 - 1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n2,0,n2);
	SortTestHelper::testSort("Shell Sort",ShellSort,arr, n2);
	delete[] arr;
	cout<<""<<endl;



	cout<<"Test for Random Array, size = "<<n1<<", random range [0, "<<n1<<"]"<<endl;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Merge Sort",MergeSort, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Merge Sort - BTU",MergeSortBTU, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Quick Sort", quickSort, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Heap Sort", heapSort1, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Heap Sort 2", heapSort2, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,n1);
	SortTestHelper::testSort("Heap Sort 3", heapSort, arr, n1);
	delete[] arr;

	cout<<""<<endl;

  	int swapTimes = 100;
	cout<<"Test for Random Nearly Ordered Array, size = "<<n1<<", swap time = "<<swapTimes<<endl;
	arr = SortTestHelper::generateNearlyOrderedArray(n1,100);
	SortTestHelper::testSort("Merge Sort",MergeSort, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateNearlyOrderedArray(n1,100);
	SortTestHelper::testSort("Quick Sort", quickSort, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateNearlyOrderedArray(n1,100);
	SortTestHelper::testSort("Heap Sort", heapSort1, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateNearlyOrderedArray(n1,100);
	SortTestHelper::testSort("Heap Sort 2", heapSort2, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateNearlyOrderedArray(n1,100);
	SortTestHelper::testSort("Heap Sort 3", heapSort, arr, n1);
	delete[] arr;
	cout<<""<<endl;

	cout<<"Test for Repeat Random Array, size = "<<n1<<", random range [0,10]"<<endl;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Merge Sort", MergeSort, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Quick Sort", quickSort, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Quick Sort - 2 Way", quickSort2, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Quick Sort - 3 Way", quickSort3, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Heap Sort", heapSort1, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Heap Sort 2", heapSort2, arr, n1);
	delete[] arr;
	arr = SortTestHelper::generateRandomArray(n1,0,10);
	SortTestHelper::testSort("Heap Sort 3", heapSort, arr, n1);
	delete[] arr;

 	system("pause");

	return 0;
}

