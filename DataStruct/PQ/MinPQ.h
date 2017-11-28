#ifndef MINPQ_H
#define MINPQ_H
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
class MinPQ
{
public:
public:
	MinPQ();							//默认构造空队列
	MinPQ(int n);						//用n构造
	MinPQ(T a[], int n);				//用数组构造

	void insert(T v);					//末尾插入 
	T	 delMax();						//头部删除 
	bool isEmpty();						//判空
	int  size();						//队列大小
	T	 min();							//访问最小元素


private:
	void swim(int k);					//尾部新数据重排
	void sink(int k);					//头部新数据重排
	void printTest();					//打印堆数据

	T* pq;								//内置数组
	int N;								//当前数据量
	int C;								//数据容量

public:
	static void sink(int a[], int k, int n);
	static void heapSort(int a[], int n);
	static int MinPQ<T>::pq_Container();
	static int MinPQ<T>::HeapOpt();
};

#endif //MINPQ_H
