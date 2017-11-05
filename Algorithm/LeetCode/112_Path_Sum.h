#include "stdafx.h"


//1、注意递归终止条件

bool hasPathSum(TreeNode* root, int sum) {
	if(!root)
		return false;	
	else if(root->val == sum && !root->left && !root->right)//必须遍历到叶子结点的时候才能做判断
		return true;
	else
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}



void test_112(){
	TreeNode* p = new TreeNode(0);
	p->left = NULL;
	p->right = NULL;
	bool i = hasPathSum(NULL, 22);
}