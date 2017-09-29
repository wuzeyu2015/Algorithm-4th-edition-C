#include "stdafx.h"


vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

	vector<vector<int>> vresult(0,vector<int>());
	queue<TreeNode*> iqueue;
	vector<int> ilevel;
	bool rFlag = false;
	if(!root)
		return vresult;

	iqueue.push(root);						//构建第一层
	iqueue.push(NULL);

	while(!iqueue.empty()){
		TreeNode* node = iqueue.front();
		iqueue.pop();
		if(node == NULL){						//本层数据已经全部出队进入ilevel
			if(rFlag) reverse(ilevel.begin(), ilevel.end());
			vresult.push_back(ilevel);	
			ilevel.clear();

			if(!iqueue.empty())
				iqueue.push(NULL);				//下一层数据已经全部进入队列，插入分割标记null
			rFlag = !rFlag;
		}
		else{								//继续往ilevel放入下一层的数据
			ilevel.push_back(node->val);
			if(node->left)
				iqueue.push(node->left);
			if(node->right)
				iqueue.push(node->right);
		}
	}
	return vresult;
}

void test_103(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	zigzagLevelOrder(root);
}