// SequentialSearchST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentialSearchST.h"
#include "BinarySearchST.h"
#include "BST.h"


int main()
{
	//无序链表的顺序查找
	//SequentialSearchST<string, int>::main(1);

	//有序数组的二分查找
	//BinarySearchST<string, int>::main(1);

	//二叉查找树
	BST<string, int>::main(1);
	//BST接口测试
	BST<string, int>::main2();
	system("pause");
    return 0;
}

//1.string a == NULL 的问题 ex: string test(){return NULL;}返回触发断言错误

//2.模板实例化的问题，模板类的obj中如果没有实例的调用，则不会生成类实现代码，所以main.obj中找不到类实现。
//2.模板类方法中调用模板变量不存在的方法，编译会通过（编译过程没有实例化模板类的情况下）
// Value BST<Key, Value>::get(TreeNode* root, Key key)
// {
// 	key.teset();

//3.用到了string对象数组keyarry，针对数组的操作可以和内置数组相同
//3.sizeof(keys)/sizeof(string)可用，keys为string数组

//4.while (getline(ifs, read, ' ')) //以‘ ’为分割（读取单词） 遇到文件换行时读入了"\nlpp"

//5.函数参数传递指针TreeNode*注意引用问题
//6.不要将两个语句写在一行ex:Key BST<Key, Value>::ceiling(Key key)中 if (pNode == NULL) return "NULL"，string类型不能与NULL转换;