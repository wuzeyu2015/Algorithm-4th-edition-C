#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class Key, class Value>
class RedBlackBST
{
public:
	RedBlackBST();
	~RedBlackBST();
private:
	class TreeNode
	{
	public:
		TreeNode(Key key, Value val, int N, bool color)
		{
			this->key = key; this->val = val; this->N = N;
			this->left = NULL;
			this->right = NULL;
			this->color = color;
		}
		TreeNode(TreeNode* pnode)
		{
			this->key = pnode->key; 
			this->val = pnode->val; 
			this->N = pnode->N;
			this->left = pnode->left;
			this->right = pnode->right;
		}
		Key key;
		Value val;
		TreeNode* left;
		TreeNode* right;
		int N; //nodes in subtree rooted here

		//-------------------红黑树--------------------------
		bool color;//父节点指向此链接的颜色 红-TRUE 黑-FALSE
		//---------------------------------------------------
	};

public:
	//api
	Value get(Key key);
	//----------改红黑树--------------
	void put(Key key, Value val);
	//------------end-----------------
	bool contains(Key key);
	int size();
	bool isEmpty();
	vector<Key>* keys();//读取keys

	//orderd st api
	Key min();
	Key max();
	TreeNode* nodemin();
	TreeNode* nodemax();
	Key floor(Key key);
	Key ceiling(Key key);
	Key select(int k);// key of rank k, notice the null pointer!
	int rank(Key key);
	void deleteMin();
	void deleteMax();
	void del(Key key);
	int size(Key lo, Key hi);
	vector<Key>* keys(Key lo, Key hi); //keys in[lo..hi], in sorted order

private:
	Key min(TreeNode* proot);
	Key max(TreeNode* proot);
	TreeNode* nodemin(TreeNode* proot);
	TreeNode* nodemax(TreeNode* proot);
	int size(TreeNode* proot);
	Value get(TreeNode* proot, Key key);
	//----------改红黑树--------------
	TreeNode* put(TreeNode* pnode, Key key, Value val);
	//-------------end----------------
	void keys(TreeNode* proot, vector<Key>* pkeyarr);
	void keys(TreeNode* proot, vector<Key>* pkeyarr, Key lo, Key hi); //keys in[lo..hi], in sorted order
	TreeNode* floor(TreeNode* pNode, Key key);
	TreeNode* ceiling(TreeNode* pNode, Key key);
	int rank(TreeNode* proot, Key key);
	Key select(TreeNode* proot, int k);// key of rank k
	TreeNode* deleteMin(TreeNode* proot);
	TreeNode* deleteMax(TreeNode* proot);
	TreeNode* del(TreeNode* proot, Key key);
	int size(TreeNode* proot, Key lo, Key hi); //number of keys in[lo..hi]

	//----------红黑树，三种不同的旋转方式--------------
	bool isRead(TreeNode* proot);
	TreeNode* rotateLeft(TreeNode* proot);
	TreeNode* rotateRight(TreeNode* proot);
	void	  flipColors(TreeNode* proot);
	//--------------------------------------------------
public:
	//test entrance
	static void main(int minLen);//put、get 文本词频统计
	static void main2();//extended api 的小规模数据测试
private:
	TreeNode* proot; // root of RedBlackBST

};
//1.rotateRight按照rotateLeft相反方向填写即可。