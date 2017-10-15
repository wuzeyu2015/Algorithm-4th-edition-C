#include "stdafx.h"



int maxDepth(TreeNode* root) {

	if(!root) return 0;
	return 1 + max(maxDepth(root->left),maxDepth(root->right));
}



void test_104(){

	int i = maxDepth(NULL);
}

