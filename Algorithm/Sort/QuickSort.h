#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "InsetionSort.h"
#include "SortTestHelper.h"
#include <time.h>
#include <vector>

//打算重新学习下算法，顺便把相关的东西整理到自己博客上，博客一搜重复的内容一大片，不论是正确还是错误的都带着很多主观看法，所以写这个不是为了成为参考资料，只为整理下自己的思路、备忘，如果被网路上的同学们检索到，希望大家能够自己甄别其中好坏，有问题的地方，也希望能够提出来大家共同学习。
//这里从快速排序和归并排序开始，因为对于新入行的同学来讲，这两个排序是理解递归的一个很好的切入点。



//直接进入主题，快排思想，就是把数组首位数字v放入数组有序时它该处的位置，同时使其左右数据满足如下描述性质:
//[|v|..................] ==> [....<v....|v|....>v.....]
//这个步骤称之为partition，可以发现经过一次partition，v的序列位定下来了,同时其他的数据虽然没有排好序，但是至少处在它该处的区间。
//然后对<v和>v的区间再次进行partition（递归），可以预见区间被划分得越来越多也越来越小，数据被分割得越来越精确（接近它的序列位）
//最后完全停留在它的序列位上，此时整个数组有序。
//类似于二分法，此数组理想情况下被分割的次数是logN，每次分割后，遍历数据量为N，时间复杂度NlogN。
//此时可以写出快排伪代码：

int _partition(int a[], int lo, int hi);
void _quicksort(int a[], int lo, int hi){
	if (lo >= hi)
		return;
	int j = _partition(a, lo, hi);
	_quicksort(a, lo, j - 1);
	_quicksort(a, j + 1, hi);
}
//看起来道理很简单是不是？我们只需要实现核心算法partition就可以了，partition过程中区间处于以下状态：
//[(v, lo) | .....<v..... | i......j | .....>v.....hi]
//其中索引上i、j参数需要明确它们的含义：
//i：右遍历指针，满足[lo, i) < v
//j：左遍历指针，满足(j, hi] > v
//由i和j来找出v的序列位

//那么问题来了，整个递归结构很清晰，但是前（启动partition：各个参数初始值）、后（退出partition：退出条件）两个部分如何分析？
int _partition(int a[], int lo, int hi){
	int i = lo;
	int j = hi + 1;
	int v = a[lo];
	while(true){
		while(a[++i] < v){ 
			if (i >= hi) break;
		}
		while(a[--j] > v){
			if (j <= lo) break;
		}
		if (i >= j)		// ">=" 还是 ">" ？
			break;
		swap(a[i], a[j]);
	}
	swap(a[lo], a[j]);
	return j;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
void quicksort(int a[], int n){
	_quicksort(a, 0, n - 1);
}
void testQuickSort(){
	int n = 10000;
	int* arr = SortTestHelper::generateRandomArray(n, 0, n);
	SortTestHelper::testSort("Quick Sort", quicksort, arr, n);
}
// part功能实现
// 对arr[l...r]部分进行partition操作
// 返回p,使arr[l, p-1] < arr[p] ; arr[p+1, r] > arr[p]
int __partition1(int arr[], int l, int r);
void __quicksort1(int arr[], int l, int r);
void quickSort1(int arr[], int n);

int __partition2(int arr[], int l, int r);
void __quicksort2(int arr[], int l, int r);
void quickSort2(int arr[], int n);

int __partition3(int arr[], int l, int r);
void __quicksort3(int arr[], int l, int r);
void quickSort3(int arr[], int n);


//////////////////////////////////////////////////////////
int __partition1(int arr[], int l, int r){
	int v = arr[l];
	int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
	for( int i = l + 1 ; i <= r ; i ++ )
		if( arr[i] < v ){
			j ++;
			swap( arr[j] , arr[i] );
		}

		swap( arr[l] , arr[j]);

		return j;
}
void __quicksort1(int arr[], int l, int r)
{
	//1.到达递归临界条件（分割数组不用再进行排序）
	if( l >= r )
		return;

	int l_partpos = __partition1(arr, l, r);
	__quicksort1(arr, l, l_partpos - 1);
	__quicksort1(arr, l_partpos + 1, r);
}
void quickSort1(int arr[], int n)
{
	__quicksort1(arr, 0, n-1);
}

////////////////////////////////////////////////////////////
int __partition2(int arr[], int l, int r)
{
	int ref = arr[l];
	int i = l + 1;
	int j = r;
	while(1)
	{
		while((i <= r) && (arr[i] < ref)) i++;
		while((j >= l + 1) && (arr[j] > ref)) j--;
		if(i > j)
			break;
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
	swap( arr[l] , arr[j]);   
	return j;
}
void __quicksort2(int arr[], int l, int r)
{
	if( l >= r )
		return;

	int l_partpos = __partition2(arr, l, r);
	__quicksort2(arr, l, l_partpos - 1);
	__quicksort2(arr, l_partpos + 1, r);
}
void quickSort2(int arr[], int n)
{
	__quicksort2(arr, 0, n-1);
}

////////////////////////////////////////////////////
void __quicksort3(int arr[], int l, int r)
{
	if( l >= r )
		return;
	//partition初始状态
	//(v\l\lt)i...............................(r\gt)
	//partition中
	//l....<v.....|lt...=v...|i...?v...gt|...>v...r
	int v = arr[l];
	int lt = l;      
	int gt = r;  
	int i = l+1;
	while( i <= gt ){
		if(arr[i] < v)	swap(arr[i++], arr[lt++]);
		else if(arr[i] > v)	swap(arr[i], arr[gt--]);
		else i++;
	}
	//partition后
	//l....<v.....|lt...=v....(gt/i)|...>v...r	[lt, gt]范围内都是重复的基准元素,无需对其再进行排序
	__quicksort3(arr, l, lt - 1);
	__quicksort3(arr, gt + 1, r);
}

void quickSort3(int arr[], int n)
{
	__quicksort3(arr, 0, n-1);
}







#endif //QUICKSORT_H