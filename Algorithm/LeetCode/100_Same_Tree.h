#include "stdafx.h"
#pragma once


bool isSameTree(TreeNode* p, TreeNode* q) {
	if(!p || !q)
		return p == q;

	if(p->val == q->val)
		return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
	return false;
}



void test_100(){
	TreeNode* p = new TreeNode(0);
	p->left = NULL;
	p->right = NULL;
	TreeNode* q = new TreeNode(1);
	q->left = NULL;
	q->right = NULL;
	bool i = isSameTree(p,q);
}