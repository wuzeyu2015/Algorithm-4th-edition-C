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
#include <ctime>
using namespace std;

template<typename T>
class MinPQ
{
public:
public:
	MinPQ();							//默认构造空队列
	MinPQ(int max);						//初始容量为max
	MinPQ(T a[], int n);				//用a[]数组创建

	void insert(T v);					//末尾插入 
	T	 delMin();						//头部删除 
	T	 min();							//返回最小元素
	bool isEmpty();						//判空
	int  size();						//返回队列元素个数


private:
	void swim(int k);					//尾部新数据重排
	void sink(int k);					//头部新数据重排

	void minPQCheck();					//检查队列是否满足最小堆

	T* pq;								//内置数组
	int N;								//当前数据量\当前队尾索引
	int C;								//数据容量

private:
	void printTest();					//打印堆数据

public:
	static int MinPQ<T>::testMinPQ();
};

#endif //MINPQ_H
