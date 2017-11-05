#include "stdafx.h"
#pragma once


TreeNode* invertTree(TreeNode* root) {
	if(!root)
		return root;

	swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}



void test_226(){

	invertTree(NULL);
}