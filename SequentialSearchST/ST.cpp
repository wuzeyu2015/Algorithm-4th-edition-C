// SequentialSearchST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentialSearchST.h"
#include "BinarySearchST.h"



int main()
{
	//SequentialSearchST<string, int>::main(8);
	BinarySearchST<string, int>::main(1);
	system("pause");
    return 0;
}

//1.string a == NULL 的问题
//2.模板实例化的问题
//3.string对象
