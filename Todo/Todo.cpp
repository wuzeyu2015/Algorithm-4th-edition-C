// Todo.cpp : 定义控制台应用程序的入口点。
//                                                                                                                                                                                                                                                                                                                                                                                                                                                                           

#include "stdafx.h"
#include<string>
#include <vector>
using namespace std;

// string testdemo1(string a){
// 	if (a == NULL);
// 	return NULL;
// }
// string testdemo2(int a) {
// 	if (a == NULL);
// 	return NULL;
// }

int main()
{
	string strtest = "fffffffffffffffffffffffffffffffffffffffffffffffff";
	int ret = sizeof(strtest);
	string* p = new string[4];
	memset(p, 0, 4 * sizeof(string));
	//testdemo1(NULL);
    return 0;
}