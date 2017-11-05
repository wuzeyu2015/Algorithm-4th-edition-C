#include "stdafx.h"
#include "math.h"

//超时
// int countNodes(TreeNode* root) {
// 	if (root == NULL)
// 		return 0;
// 	return 1 + countNodes(root->left) + countNodes(root->right);
// }


//最简洁的版本，利用满二叉树节点数为2^h - 1来优化其中满二叉子树的时间效率
int leftH(TreeNode* root) {
	int lh = 0;
	while(root){
		lh++;
		root = root->left;
	}
	return lh;
}	
int rightH(TreeNode* root) {
	int rh = 0;
	while(root){
		rh++;
		root = root->right;
	}
	return rh;
}

int countNodes(TreeNode* root) {
	int l = leftH(root);
	int r = rightH(root);
	if(l == r)	return pow((double)2, l) - 1;
	else{
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
}

//最下面一层去掉，整棵树就是满二叉树，再加上最后一层的遍历？


void test_222(){
	TreeNode* p = new TreeNode(0);
	p->left = NULL;
	p->right = NULL;
	bool i = countNodes(NULL);
}