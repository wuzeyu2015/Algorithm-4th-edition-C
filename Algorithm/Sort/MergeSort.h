#ifndef MERGE_H
#define MERGE_H
#include "SortTestHelper.h"
// class MergeSort{
// 
// public:
// 	MergeSort(int a[], int length){
// 		aux = new int[length];
// 		memset(aux, 0, length);
// 		sort(a, 0, length - 1);
// 		memcpy(a, aux, length * sizeof(int));
// 	}
// 	~MergeSort(){
// 		delete aux;
// 	}
// 
// private:
// 	int* aux;
// 	void merge(int a[], int lo, int mid, int hi);
// 	void sort(int a[], int lo, int hi);
// };

void merge(int a[], int lo, int mid, int hi, int* aux){
	int i = lo;
	int j = mid + 1;
	int k = lo;
	//[(lo\i).....sorted array.....mid|j.....sorted array.....hi]  ==>  [k..............]
	while(k <= hi){
		//控制流中最好不要把前连个分支当成后两个分支的前置条件，后两个分支显示声明出来比较好
		if (i > mid) { aux[k++] = a[j++]; }
		else if (j > hi) { aux[k++] = a[i++]; }
		else if (a[i] < a[j]) { aux[k++] = a[i++]; }
		else if (a[i] >= a[j]) { aux[k++] = a[j++]; }
	}
	for(int i = lo; i <= hi; i++){
		a[i] = aux[i];
	}
}
void sort(int a[], int lo, int hi, int* aux){
	if (lo >= hi)
		return;
	int mid = (lo + hi) / 2;
	sort(a, lo, mid, aux);
	sort(a, mid + 1, hi, aux);
	merge(a, lo, mid, hi, aux);
}
void MergeSort(int a[], int n) {
	int *aux = new int[n];
	memset(aux, 0, n);
	sort(a, 0, n - 1, aux);
	memcpy(a, aux, n * sizeof(int));
}


void testMergeSort() {
 	int n = 100000;
 	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("Merge Sort", MergeSort, arr, n);
}
#endif //MERGE_H
