#include "stdafx.h"


vector<int> inorderTraversal(TreeNode* root) {
	if(root == NULL)
		return vector<int>();

	vector<int> ivector;
	stack<TreeNode *> stack;
	TreeNode* curroot = root;
	while (!stack.empty() || curroot != NULL){
		//遍历到左叶子节点，入队、出栈，再按照这个方式访问它的右节点
		while(curroot){
			stack.push(curroot);
			curroot = curroot->left;
		}
		//左叶子节点
		curroot = stack.top();
		// Add after all left children
		ivector.push_back(curroot->val);
		stack.pop();

		curroot = curroot->right;

	}
	return ivector;
}

void test_94(){
	string sarray[] = {"2", "1", "+", "3", "*"};
	vector<string> svector(sarray, sarray + 5);
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	inorderTraversal(root);
}

