// SequentialSearchST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentialSearchST.h"
#include "BinarySearchST.h"
#include "BST.h"


int main()
{
	//SequentialSearchST<string, int>::main(1);
	//BinarySearchST<string, int>::main(1);
	//BST<string, int>::main(1);
	BST<string, int>::main2();
	system("pause");
    return 0;
}

//1.string a == NULL 的问题 ex: string test(){return NULL;}返回触发断言错误
//2.模板实例化的问题
//3.用到了string对象数组keyarry，针对数组的操作可以和内置数组相同
//3.sizeof(keys)/sizeof(string)可用，keys为string数组
//4.while (getline(ifs, read, ' ')) //以‘ ’为分割（读取单词） 遇到文件换行时读入了"\nlpp"
//5.函数参数传递指针TreeNode*注意引用问题
//6.不要将两个语句写在一行ex:Key BST<Key, Value>::ceiling(Key key)中 if (pNode == NULL) return "NULL"，string类型不能与NULL转换;