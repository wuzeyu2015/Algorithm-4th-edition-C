#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class Key, class Value>
class BST
{
public:
	BST();
	~BST();
private:
	class TreeNode
	{
	public:
		TreeNode(Key key, Value val, int N)
		{
			this->key = key; this->val = val; this->N = N;
			this->left = NULL;
			this->right = NULL;
		}
		Key key;
		Value val;
		TreeNode* left;
		TreeNode* right;
		int N; //nodes in subtree rooted here
	};
public:
	Value get(Key key);
	void put(Key key, Value val);
	bool contains(Key key);
	int size();
	bool isEmpty();
	vector<Key>* keys();//读取keys

	//orderd st can extend these api as follows
	Key min();
	Key max();
	void del(Key key);
	Key floor(Key key);
	Key ceiling(Key key);
	Key select(int k);// key of rank k
	void deleteMin();
	void deleteMax();
	int size(Key lo, Key hi); //number of keys in[lo..hi]
	vector<Key>* keys(Key lo, Key hi); //keys in[lo..hi], in sorted order

private:
	int rank(Key key);
	int size(TreeNode* proot);
	Value get(TreeNode* proot, Key key);
	TreeNode*& put(TreeNode*& pnode, Key key, Value val);
	void keys(TreeNode* proot, vector<Key>* pkeyarr);
	Key min(TreeNode* proot);
	Key max(TreeNode* proot);
	TreeNode* floor(TreeNode* pNode, Key key);
	TreeNode* ceiling(TreeNode* pNode, Key key);
public:
	//test entrance
	static void main(int minLen);
	static void main2();//小规模数据测试extended api as shown above
private:
	TreeNode* proot; // root of BST

};


