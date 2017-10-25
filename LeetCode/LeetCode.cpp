// LeetCode.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

//栈应用
#include "20_Valid_Parentheses.h"
#include "150_Evaluate_Reverse_Polish_Notation.h"
#include "71_Simplify_Path.h"

#include "144_Binary_Tree_Preorder_Traversal.h"
#include "94_Binary_Tree_Inorder_Traversal.h"
//#include "145_Binary_Tree_Preorder_Traversal.h"用栈实现后续遍历没有看明白？？

//队列应用
#include "102_Binary_Tree_Level_Order_Traversal.h"//BFS、Queue
#include "103_Binary_Tree_Zigzag_Level_Order_Traversal.h"
#include "107_Binary_Tree_Level_Order_Traversal_II.h"
#include "199_Binary_Tree_Right_Side_View.h"
#include "279_Perfect_Squares.h"//只会dp解法，BFS、Queue没看懂？（另外还可用图？）
#include "127_Word_Ladder.h"//BFS、Queue、只要求返回层数。
#include "126_Word_LadderII.h"//BFS、Queue、如何输出路径？？

//优先队列应用
#include "347_Top_K_Frequent_Elements.h"
#include "23_Merge_k_Sorted_Lists.h"

//二叉树属性问题（递归）
#include "104_Maximum_Depth_of_Binary_Tree.h"
#include "111_Minimum_Depth_of_Binary_Tree.h"
#include "226_Invert_Binary_Tree.h"
#include "100_Same_Tree.h"
#include "101_Symmetric_Tree.h"
#include "222_Count_Complete_Tree_Nodes.h"
#include "110_Balanced_Binary_Tree.h"

//终止条件应用（递归）
#include "112_Path_Sum.h"

//其他
#include "125_Valid_Palindrome.h"//递归判断回文
#include "43_Multiply_Strings.h"//大数相乘
class Ctest {

public:
	Ctest& operator + (Ctest& cc) {
		int i = cc.a;
		return *this;
	}
private:
	int a;

};

int _tmain(int argc, _TCHAR* argv[])
{
	test_20();
	test_71();

	test_144();
	test_94();

	test_102();
	test_103();
	test_107();
	test_199();
	test_279();
	test_127();

	test_347();
	test_23();

	test_104();
	test_111();
	test_226();
	test_100();
	test_222();
	test_110();
	test_101();
	test_112();

	test_125();
	test_043();


	return 0;
}

