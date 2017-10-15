#include "stdafx.h"


//不要过于在意函数执行流程，以二叉树中任意位置的三个节点来分析
int minDepth(TreeNode* root) {

	if(!root) return 0;
	if(!root->left) return 1 + minDepth(root->right);
	if(!root->right) return 1 + minDepth(root->left);
	return 1 + min(minDepth(root->left),minDepth(root->right));
}



void test_111(){

	int i = minDepth(NULL);
}