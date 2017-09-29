#include "stdafx.h"

vector<int> postorderTraversal(TreeNode* root) {
	if(root == NULL)
		return vector<int>();

	vector<int> ivector;
	stack<TreeNode *> stack;
	TreeNode* curroot = root;
	while (!stack.empty() || curroot != NULL){
		//遍历到右叶子节点，入队、出栈，再按照这个方式访问它的左节点
		while(curroot){
			stack.push(curroot);
			curroot = curroot->left;
		}
		//左叶子节点
		curroot = stack.top();
		ivector.push_back(curroot->val);
		stack.pop();

		curroot = stack.top()->right;

	}
	return ivector;
}

void test_145(){
	string sarray[] = {"2", "1", "+", "3", "*"};
	vector<string> svector(sarray, sarray + 5);
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	postorderTraversal(root);
}

