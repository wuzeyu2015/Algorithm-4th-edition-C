#include "stdafx.h"
#include "BST.h"


template<class Key, class Value>
BST<Key, Value>::BST()
{
	proot = NULL;
}

template<class Key, class Value>
BST<Key, Value>::~BST()
{
}

template<class Key, class Value>
Value BST<Key, Value>::get(Key key)
{
	return get(proot, key);
}

template<class Key, class Value>
Value BST<Key, Value>::get(TreeNode* root, Key key)
{
	if (root == NULL)
		return NULL;
	if (root->key == key)
		return root->val;
	else if (root->key < key)
		return get(root->right, key);
	else if (root->key > key)
		return get(root->left, key);
}

template<class Key, class Value>
void BST<Key, Value>::put(Key key, Value val)
{
	put(proot, key, val);
}

template<class Key, class Value>
typename BST<Key, Value>::TreeNode*& BST<Key, Value>::put(TreeNode* &pnode, Key key, Value val)
{
	if (pnode == NULL)
		return (pnode = new TreeNode(key, val, 1));

	else if (pnode->key < key)
		put(pnode->right, key, val);
	else if (pnode->key > key)
		put(pnode->left, key, val);
	else if(pnode->key == key)
		pnode->val = val;

	pnode->N = 1 + size(pnode->left) + size(pnode->right);
}
template<class Key, class Value>
bool BST<Key, Value>::contains(Key key) {
	return get(key) != NULL;
}
template<class Key, class Value>
int BST<Key, Value>::size() {
	return size(proot);
}
template<class Key, class Value>
int BST<Key, Value>::size(TreeNode* proot) {
	if (proot == NULL) 
		return 0;
	return proot->N;
}

template<class Key, class Value>
bool BST<Key, Value>::isEmpty() {
	return size() == 0;
}
template<class Key, class Value>
vector<Key>* BST<Key, Value>::keys() {
	vector<Key>* pkeyarr = new vector<Key>();
	keys(proot, pkeyarr);
	return pkeyarr;
}
template<class Key, class Value>
void BST<Key, Value>::keys(TreeNode* proot, vector<Key>* pkeyarr) {
	if (proot == NULL)
		return;
	pkeyarr->push_back(proot->key);
	keys(proot->left, pkeyarr);
	keys(proot->right, pkeyarr);
}

template<class Key, class Value>
Key BST<Key, Value>::floor(Key key) {
	if (isEmpty()) throw new exception("calls floor() with empty symbol table");
	TreeNode* pNode = floor(proot, key);
	if (pNode == NULL) return NULL;
	else return pNode->key;	
}
template<class Key, class Value>
typename BST<Key, Value>::TreeNode* BST<Key, Value>::floor(TreeNode* proot, Key key) {
	if (proot == NULL)
		return NULL;
	if (key < proot->key)
		return floor(proot->left, key);
	else if (key > proot->key) {
		TreeNode*  pret = floor(proot->right, key);
		if (pret)   return pret;
		else	    return proot;
	}
	else if (key == proot->key)
		return proot;

}

template class BST<string, int>;



//测试入口函数
template<class Key, class Value>
void BST<Key, Value>::main(int minLen) {

	BST<string, int>* st = new BST<string, int>();

	ifstream ifs("tale.txt");//初始化一个输入流
	string read;
	while (ifs >> read)
	{
		if (read.length() < minLen) continue;
		if (st->contains(read)) {
			st->put(read, st->get(read) + 1);
		}
		else {
			st->put(read, 1);
		}
		//cout << read << endl;
	}
	// find a key with the highest frequency count
	string maxfreqstring = " ";
	st->put(maxfreqstring, 0);
	vector<Key>* vp = st->keys();
	for (string cur : *vp) {
		if (st->get(cur) > st->get(maxfreqstring))
			maxfreqstring = cur;
	}
	cout << "there are:" << st->size() << " different words" << endl;
	cout << "highest frequency:" << maxfreqstring << endl;
	cout << "count:" << st->get(maxfreqstring) << endl;
}