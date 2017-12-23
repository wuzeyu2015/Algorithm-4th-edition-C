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
// string testdemo1(string a){
// 	if (a == NULL);
// 	return NULL;
// }
// string testdemo2(int a) {
// 	if (a == NULL);
// 	return NULL;
// }
//2.模板实例化的问题
//3.用到了string对象数组keyarry，针对数组的操作可以和内置数组相同
//4.while (getline(ifs, read, ' ')) //以‘ ’为分割（读取单词） 遇到文件换行时读入了"\nlpp"
