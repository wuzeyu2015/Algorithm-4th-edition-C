#ifndef MERGE_H
#define MERGE_H
#include "InsetionSort.h"


int __merge(int arr[], int l, int l_middle, int r);

void __mergeSort(int arr[], int l, int r);

void MergeSort(int arr[], int n);

//////////////////////////////////////////////////////////

int __merge(int arr[], int l, int l_middle, int r)
{
	//1.创建辅助空间
	int* aux = new int[r - l + 1];
	for(int i = 0; i <= r - l; i++)
	{
		aux[i] = arr[l + i];
	}
	//2.设置索引:i、j分别是aux[]的左边第一个、右边第一个;
	//k遍历arr开始这次的归并,注意[i, j]和[l, r]的相对位置关系
	int i = 0;
	int j = l_middle - l + 1;
	for(int k = l; k <= r; k++)
	{
		//3.注意归并过程中越界情况的处理
		if(i > l_middle - l)
		{
			arr[k] = aux[j];
			j++;
		}
		else if(j > r - l)
		{
			arr[k] = aux[i];
			i++;
		}
		//4.归并过程中正常情况的处理
		else if(aux[i] > aux[j])
		{
			arr[k] = aux[j];
			j++;
		}
		else
		{
			arr[k] = aux[i];
			i++;
		}
	}
	return 0;
}

void __mergeSort(int arr[], int l, int r)
{
	//1.到达递归临界条件（分割数组不用再进行排序）
	if( l >= r )
		return;
// 	if( r - l < 15 )
// 	{
// 		__portionInsertionSort(arr, l, r);
// 		return;
// 	}
	int l_middle = (l + r) / 2;
	__mergeSort(arr, l, l_middle);
	__mergeSort(arr, l_middle + 1, r);

//	if(arr[l_middle] > arr[l_middle + 1])
	__merge(arr, l, l_middle, r);
}

void MergeSort(int arr[], int n)
{
	__mergeSort(arr, 0, n-1);
}

void MergeSortBTU(int arr[], int n)//用for循环，自底向上的迭代
{
	for(int sz = 1; sz <=n; sz += sz)
	{
		for(int i = 0; i < n - sz + 1; i += 2*sz)
		{
			//将[i, i + sz - 1]、 [i + sz, i + 2sz - 1]进行归并
			__merge(arr, i, i + sz - 1, min((i + 2*sz -1), n - 1));
		}
	}
}


#endif //MERGE_H
