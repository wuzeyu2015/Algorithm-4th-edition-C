// LeetCode.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

//栈的应用
#include "20_Valid_Parentheses.h"
#include "150_Evaluate_Reverse_Polish_Notation.h"
#include "71_Simplify_Path.h"

#include "144_Binary_Tree_Preorder_Traversal.h"
#include "94_Binary_Tree_Inorder_Traversal.h"
//#include "145_Binary_Tree_Preorder_Traversal.h"用栈实现后续遍历没有看明白

//队列的应用
#include "102_Binary_Tree_Level_Order_Traversal.h"
#include "103_Binary_Tree_Zigzag_Level_Order_Traversal.h"
#include "107_Binary_Tree_Level_Order_Traversal_II.h"
#include "199_Binary_Tree_Right_Side_View.h"
#include "279_Perfect_Squares.h"//只会dp解法，用Queue、bfs没看懂（图？Queue）


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
	return 0;
}

