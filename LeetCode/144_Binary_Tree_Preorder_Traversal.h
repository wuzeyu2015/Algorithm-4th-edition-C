#include "stdafx.h"


// vector<int> preorderTraversal(TreeNode* root) {
// 	if(root == NULL)
// 		return vector<int>();
// 
// 	vector<int> ivector;
// 	stack<TreeNode *> stack;
// 	stack.push(root);
// 
// 	while (!stack.empty()){
// 		//当前要出栈的节点
// 		TreeNode curPop = *stack.top();
// 		ivector.push_back(curPop.val);
// 		stack.pop();
// 		if(curPop.right)
// 			stack.push(curPop.right);
// 		if(curPop.left)
// 			stack.push(curPop.left);
// 	}
// 	return ivector;
// }
vector<int> preorderTraversal(TreeNode* root) {
	if(root == NULL)
		return vector<int>();

	vector<int> ivector;
	stack<TreeNode *> stack;
	TreeNode* curroot = root;
	while (!stack.empty() || curroot != NULL){
		if(curroot != NULL) {
			stack.push(curroot);
			// Add before going to children
			ivector.push_back(curroot->val);
			curroot = curroot->left;
		} else {
			TreeNode* node = stack.top();
			stack.pop();
			curroot = node->right;   
		}

	}
	return ivector;
}

void test_144(){
	string sarray[] = {"2", "1", "+", "3", "*"};
	vector<string> svector(sarray, sarray + 5);
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	preorderTraversal(root);
}

