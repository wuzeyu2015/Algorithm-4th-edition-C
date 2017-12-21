// SequentialSearchST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentialSearchST.h"
#include "BinarySearchST.h"



int main()
{
	//SequentialSearchST<string, int>::testmain(8);
	BinarySearchST<string, int>::testmain(8);
	system("pause");
    return 0;
}

//1.string a == NULL 的问题
//2.模板实例化的问题
