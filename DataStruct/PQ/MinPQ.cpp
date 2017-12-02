// MinPQ.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "MinPQ.h"
template<typename T>
MinPQ<T>::MinPQ() {
	//
	//
}

template<typename T>
MinPQ<T>::MinPQ(int max) :N(0), C(max) {
	pq = new T[max + 1];//索引要从1开始
}

template<typename T>
MinPQ<T>::MinPQ(T a[], int n) : N(n), C(n) {
	//
	//
}

template<typename T>
void MinPQ<T>::insert(T v) {
	pq[++N] = v;
	swim(N);
	minPQCheck();
}

template<typename T>
T MinPQ<T>::delMin() {
	T ret = min();
	pq[1] = pq[N];
	pq[N--] = NULL;
	sink(1);
	minPQCheck();
	return ret;
}
template<typename T>
bool MinPQ<T>::isEmpty() {
	return N == 0;
}

template<typename T>
int MinPQ<T>::size() {
	return N;
}

template<typename T>
T MinPQ<T>::min() {
	return pq[1];
}

template<typename T>
void MinPQ<T>::swim(int k) {
	while ((k > 1) && (pq[k] < pq[k / 2])) {
		swap(pq[k], pq[k / 2]);
		k = k / 2;
	}
}

template<typename T>
void MinPQ<T>::sink(int k) {
	while (2 * k <= N) {
		if ((2 * k + 1 <= N) && (pq[2 * k + 1] < pq[2 * k])) {
			if (pq[k] > pq[2 * k + 1]) {
				swap(pq[k], pq[2 * k + 1]);
				k = 2 * k + 1;
			}
			else
				break;
		}
		else if (pq[k] > pq[2 * k]) {
			swap(pq[k], pq[2 * k]);
			k = 2 * k;
		}
		else
			break;
	}
}
template<typename T>
void MinPQ<T>::minPQCheck(void) {
	for (int i = 1; i <= N / 2; i++) {
		if ((2 * i + 1 <= N) && (pq[i] > pq[2 * i] || pq[i] > pq[2 * i + 1])) {
			assert(false);
		}
	}
}
//////////////////////////////////////////////////////////
//独立的堆排序接口,注意a[]从索引1开始
template<typename T>
void MinPQ<T>::sink(int a[], int k, int n) {			//头部新数据重排
 
}

template<typename T>
void MinPQ<T>::heapSort(int a[], int n) {
 
}

template<typename T>
int MinPQ<T>::HeapOpt() {
 

	return 0;
}
template<typename T>
int MinPQ<T>::testMinPQ() {
	MinPQ<int>* pObj = new MinPQ<int>(2000);
	srand(time(NULL));
	for (int i = 0; i < 2000; i++)
		pObj->insert(rand() % 2000);

	vector<int> arr;
	for (int i = 0; i < 2000; i++) {
		arr.push_back(pObj->delMin());
	}
	for (auto n : arr) {
		cout << n << " ";
	}
	return 0;
}
template class MinPQ<int>;