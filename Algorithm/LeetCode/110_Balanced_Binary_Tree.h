#include "stdafx.h"

//O(n2)
int maxDepths(TreeNode* root) {

	if(!root) return 0;
	return 1 + max(maxDepths(root->left),maxDepths(root->right));
}
bool isBalanced(TreeNode* root) {
	if(!root) return 1;
	if(abs(maxDepths(root->left) - maxDepths(root->right)) <= 1)
		return isBalanced(root->left) && isBalanced(root->right);
	return false;
}

//O(n)??

void test_110(){
	TreeNode* p = new TreeNode(0);
	p->left = NULL;
	p->right = NULL;
	bool i = isBalanced(NULL);
}