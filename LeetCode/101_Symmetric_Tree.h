#pragma once

#include "stdafx.h"
#include "226_Invert_Binary_Tree.h"
#include "100_Same_Tree.h"


bool isSymmetric(TreeNode* root) {
	return isSameTree(root->left, invertTree(root->right));
}



void test_101() {
	TreeNode* p = new TreeNode(0);
	p->left = NULL;
	p->right = NULL;
	TreeNode* q = new TreeNode(1);
	q->left = NULL;
	q->right = NULL;
	bool i = isSymmetric(p);
}