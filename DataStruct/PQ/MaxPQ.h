#ifndef MAXPQ_H
#define MAXPQ_H
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include<functional>
using namespace std;


template<typename T>
class MaxPQ
{
public:
	MaxPQ();							//优先队列三种构造方式
	MaxPQ(int max);						//	max容量的空优先队列
	MaxPQ(T a[], int n);				//	用数组初始化优先队列

	void insert(T v);					//insert a key into the priority queue	
	
	T delMax();							//return and remove the largest key
	
	bool isEmpty();						//is the priority queue empty?
	
	int size();							//number of keys in the priority queue
	
	T max();							//return the largest key
	
	vector<int> heapSort();				//从pq中输出有序数组


private:
	void swim(int k);					//尾部新数据重排
	void sink(int k);					//头部新数据重排
	void printTest();					//打印堆数据
	 T* pq;								// heap-ordered complete binary tree
	 int N;								// in pq[1..N] with pq[0] unused 当前容量
	 int C;								// 容量上限

public:
	 static void sink(int a[], int k, int n);
	 static void heapSort(int a[], int n);
	 static int MaxPQ<T>::pq_Container();
	 static int MaxPQ<T>::HeapOpt();
};

#endif //MAXPQ_H
