// MinPQ.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "MinPQ.h"
template<typename T>
MinPQ<T>::MinPQ() {

}

template<typename T>
MinPQ<T>::MinPQ(int max) :N(0), C(max) {

}

template<typename T>
MinPQ<T>::MinPQ(T a[], int n) : N(n), C(n) {
 
}

template<typename T>
void MinPQ<T>::insert(T v) {
 
}

template<typename T>
T MinPQ<T>::delMax() {
 
}
template<typename T>
bool MinPQ<T>::isEmpty() {
 
}

template<typename T>
int MinPQ<T>::size() {
 
}

template<typename T>
T MinPQ<T>::max() {
 
}

template<typename T>
vector<int> MinPQ<T>::heapSort() {
 
}

template<typename T>
void MinPQ<T>::swim(int k) {
	while (k > 1) {
		if (pq[k] > pq[k / 2]) {
			swap(pq[k], pq[k / 2]);
			k = k / 2;
		}
		else
			break;
	}
}

template<typename T>
void MinPQ<T>::sink(int k) {
	while (2k <= N) {
		if (pq[k] < pq[2k]) {
			swap(pq[k], pq[2k]);
			k = 2k;
		}
		else
			break;
	}
}

template<typename T>
void MinPQ<T>::printTest() {
 
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

class mycomparison
{
	bool reverse;
public:
	mycomparison(const bool& revparam = false)
	{
		reverse = revparam;
	}
	bool operator() (const int& lhs, const int&rhs) const
	{
		if (reverse) return (lhs>rhs);
		else return (lhs<rhs);
	}
};

template<typename T>
int MinPQ<T>::pq_Container()
{
 
}

template class MinPQ<int>;