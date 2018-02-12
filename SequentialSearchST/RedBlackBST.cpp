#include "stdafx.h"
#include "RedBlackBST.h"
#include <sstream>

template<class Key, class Value>
RedBlackBST<Key, Value>::RedBlackBST()
{
	proot = NULL;
}

template<class Key, class Value>
RedBlackBST<Key, Value>::~RedBlackBST()
{
}

template<class Key, class Value>
Value RedBlackBST<Key, Value>::get(Key key)
{
	return get(proot, key);
}

template<class Key, class Value>
Value RedBlackBST<Key, Value>::get(TreeNode* root, Key key)
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
void RedBlackBST<Key, Value>::put(Key key, Value val)
{
	proot = put(proot, key, val);
	proot->color = false;
}

template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::put(TreeNode* pnode, Key key, Value val)
{
	if (pnode == NULL)
		return (pnode = new TreeNode(key, val, 1, true));//init the Red link with it's parent node

	else if (pnode->key < key)
		pnode->right = put(pnode->right, key, val);
	else if (pnode->key > key)
		pnode->right = put(pnode->left, key, val);
	else if (pnode->key == key)
		pnode->val = val;
	//--------------红黑判断和旋转-----------------------
	if (isRead(pnode->right) && !isRead(pnode->left))
		rotateLeft(pnode);
	if (isRead(pnode->left) && isRead(pnode->left->left))
		rotateRight(pnode);
	if (isRead(pnode->right) && isRead(pnode->left))
		flipColors(pnode);
	//----------------------------------------------------
	pnode->N = 1 + size(pnode->left) + size(pnode->right);
	return  pnode;//the same important point with 45 line
}
template<class Key, class Value>
bool RedBlackBST<Key, Value>::contains(Key key) {
	return get(key) != NULL;
}
template<class Key, class Value>
int RedBlackBST<Key, Value>::size() {
	return size(proot);
}
template<class Key, class Value>
int RedBlackBST<Key, Value>::size(TreeNode* proot) {
	if (proot == NULL)
		return 0;
	return proot->N;
}
template<class Key, class Value>
int RedBlackBST<Key, Value>::size(Key lo, Key hi) {
	return size(proot);
}
template<class Key, class Value>
int RedBlackBST<Key, Value>::size(TreeNode* proot, Key lo, Key hi) {
	if (proot == NULL)
		return 0;
	return proot->N;
}
template<class Key, class Value>
Key RedBlackBST<Key, Value>::min() {
	if (isEmpty()) throw new exception("calls min() with empty symbol table");
	return min(proot);
}
template<class Key, class Value>
Key RedBlackBST<Key, Value>::min(TreeNode* pNode) {
	if (pNode->left) return min(pNode->left);
	else             return pNode->key;
}
template<class Key, class Value>
Key RedBlackBST<Key, Value>::max() {
	if (isEmpty()) throw new exception("calls min() with empty symbol table");
	return max(proot);
}
template<class Key, class Value>
Key RedBlackBST<Key, Value>::max(TreeNode* pNode) {
	if (pNode->right) return max(pNode->right);
	else              return pNode->key;
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::nodemin() {
	if (isEmpty()) throw new exception("calls min() with empty symbol table");
	return nodemin(proot);
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::nodemin(TreeNode* pNode) {
	if (pNode->left) return nodemin(pNode->left);
	else             return pNode;
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::nodemax() {
	if (isEmpty()) throw new exception("calls min() with empty symbol table");
	return nodemax(proot);
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::nodemax(TreeNode* pNode) {
	if (pNode->right) return nodemax(pNode->right);
	else              return pNode;
}
template<class Key, class Value>
bool RedBlackBST<Key, Value>::isEmpty() {
	return size() == 0;
}
template<class Key, class Value>
vector<Key>* RedBlackBST<Key, Value>::keys() {
	vector<Key>* pkeyarr = new vector<Key>();
	keys(proot, pkeyarr);
	return pkeyarr;
}
template<class Key, class Value>
void RedBlackBST<Key, Value>::keys(TreeNode* proot, vector<Key>* pkeyarr) {
	if (proot == NULL)
		return;
	pkeyarr->push_back(proot->key);
	keys(proot->left, pkeyarr);
	keys(proot->right, pkeyarr);
}
template<class Key, class Value>
vector<Key>* RedBlackBST<Key, Value>::keys(Key lo, Key hi) {
	vector<Key>* pkeyarr = new vector<Key>();
	keys(proot, pkeyarr, lo, hi);
	return pkeyarr;
}
template<class Key, class Value>
void RedBlackBST<Key, Value>::keys(TreeNode* proot, vector<Key>* pkeyarr, Key lo, Key hi) {
	if (proot == NULL)
		return;
	pkeyarr->push_back(proot->key);
	keys(proot->left, pkeyarr);
	keys(proot->right, pkeyarr);
}
template<class Key, class Value>
int RedBlackBST<Key, Value>::rank(Key key) {
	//if (key) throw new exception("argument to rank() is null");
	return rank(proot, key);
}
template<class Key, class Value>
int RedBlackBST<Key, Value>::rank(TreeNode* proot, Key key) {
	if (proot == NULL)
		return 0;
	if (key < proot->key)
		return rank(proot->left, key);
	else if (key > proot->key)
		return 1 + size(proot->left) + rank(proot->right, key);
	else if (key == proot->key)
		return size(proot->left);
}
template<class Key, class Value>
Key RedBlackBST<Key, Value>::select(int k) {
	if (k < 0 || k >= size()) {
		throw new exception("argument to select() is invalid: " + k);
	}
	return select(proot, k);
}
template<class Key, class Value>
Key RedBlackBST<Key, Value>::select(TreeNode* proot, int k) {
	if (proot == NULL)
		return "NULL";
	int lk = size(proot->left);
	if (k < lk)
		return select(proot->left, k);
	else if (k > lk)
		return select(proot->right, k - lk - 1);
	else if (k == lk)
		return proot->key;
}

template<class Key, class Value>
Key RedBlackBST<Key, Value>::floor(Key key) {
	if (isEmpty()) throw new exception("calls floor() with empty symbol table");
	TreeNode* pNode = floor(proot, key);
	if (pNode == NULL) return NULL;
	else return pNode->key;
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::floor(TreeNode* proot, Key key) {
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
template<class Key, class Value>
Key RedBlackBST<Key, Value>::ceiling(Key key) {
	if (isEmpty()) throw new exception("calls floor() with empty symbol table");
	TreeNode* pNode = ceiling(proot, key);
	if (pNode == NULL)
		return "NULL";
	else return pNode->key;
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::ceiling(TreeNode* proot, Key key) {
	if (proot == NULL)
		return NULL;
	if (key < proot->key) {
		TreeNode*  pret = ceiling(proot->left, key);
		if (pret)   return pret;
		else	    return proot;
	}
	else if (key > proot->key)
		return ceiling(proot->right, key);
	else if (key == proot->key)
		return proot;
}

template<class Key, class Value>
void RedBlackBST<Key, Value>::deleteMin() {
	if (isEmpty()) throw new exception("Symbol table underflow");
	proot = deleteMin(proot);
	//assert check();
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::deleteMin(TreeNode* proot) {
	if (proot->left == NULL) {//proot此时为min节点
		TreeNode* temp = proot->right;
		delete proot;
		return temp;//返回ceiling(min)
	}
	else//还需要继续往left寻找min节点
		proot->left = deleteMin(proot->left);

	proot->N = 1 + size(proot->left) + size(proot->right);
	return proot;
}

template<class Key, class Value>
void RedBlackBST<Key, Value>::deleteMax() {
	if (isEmpty()) throw new exception("Symbol table underflow");
	proot = deleteMax(proot);//必须返回给proot
							 //assert check();
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::deleteMax(TreeNode* proot) {
	if (proot->right == NULL) {//proot此时为max节点
		TreeNode* temp = proot->left;
		delete proot;
		return temp;//返回floor(max)
	}
	else//还需要继续往right寻找max节点
		proot->right = deleteMax(proot->right);

	proot->N = 1 + size(proot->left) + size(proot->right);
	return proot;
}

template<class Key, class Value>
void RedBlackBST<Key, Value>::del(Key key) {
	if (isEmpty()) throw new exception("Symbol table underflow");
	proot = del(proot, key);
	//assert check();
}
template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::del(TreeNode* proot, Key key) {
	if (proot == NULL)//未命中key结束递归
		return NULL;
	if (proot->key == key) {//命中key
		if (proot->left == NULL) {
			TreeNode* pret = proot->right;
			delete proot;
			return pret;
		}
		if (proot->right == NULL) {
			TreeNode* pret = proot->left;
			delete proot;
			return pret;
		}
		else {//两边都有节点
			TreeNode* pret = new TreeNode(nodemin(proot->right));
			pret->left = proot->left;
			pret->right = deleteMin(proot->right);
			return pret;
		}
	}
	else if (proot->key < key)
		proot->right = del(proot->right, key);
	else if (proot->key > key)
		proot->left = del(proot->left, key);

	proot->N = 1 + size(proot->left) + size(proot->right);
	return proot;
}


template<class Key, class Value>
bool RedBlackBST<Key, Value>::isRead(TreeNode* proot) {
	if (proot == NULL)
		return false;
	return (proot->color == true);
}

template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::rotateLeft(TreeNode* proot){
	TreeNode* pred = proot->right;//找到右边的红节点pred，pred拥有左右子树
	proot->right = pred->left;//root右节点指向红节点的左子树
	pred->left = proot;
	pred->color = proot->color;
	proot->color = true;
	pred->N = proot->N;
	proot->N = 1 + size(proot->left) + size(proot->right);

	return pred;//返回之前的红节点作为根节点，它目前的颜色由之前的root节点的颜色决定！
}

template<class Key, class Value>
typename RedBlackBST<Key, Value>::TreeNode* RedBlackBST<Key, Value>::rotateRight(TreeNode* proot) {
	TreeNode* pred = proot->left;//找到右边的红节点pred，pred拥有左右子树
	proot->left = pred->right;//root右节点指向红节点的左子树
	pred->right = proot;
	pred->color = proot->color;
	proot->color = true;
	pred->N = proot->N;
	proot->N = 1 + size(proot->left) + size(proot->right);

	return pred;//返回之前的红节点作为根节点，它目前的颜色由之前的root节点的颜色决定！
}

template<class Key, class Value>
void RedBlackBST<Key, Value>::flipColors(TreeNode* proot) {
	proot->color = true;
	proot->left.color = false;
	proot->right.color = false;
}

//测试入口函数
template<class Key, class Value>
void RedBlackBST<Key, Value>::main(int minLen) {

	RedBlackBST<string, int>* st = new RedBlackBST<string, int>();

	ifstream ifs("singlewords.txt");//初始化一个输入流
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

//测试入口函数2
template<class Key, class Value>
void RedBlackBST<Key, Value>::main2() {

	RedBlackBST<string, int>* st = new RedBlackBST<string, int>();
	string keys[] = { "S", "E", "A", "R", "C", "H", "E", "X", "A", "M", "P", "L", "E" };
	for (int i = 0; i < sizeof(keys) / sizeof(string); i++)
		st->put(keys[i], i);

	cout << "size = " << st->size() << endl;
	cout << "min = " << st->min() << endl;
	cout << "max = " << st->max() << endl;


	// print keys in order using allKeys()
	cout << "Testing keys()" << endl;
	cout << "--------------------------------" << endl;
	vector<Key>* pkeys = st->keys();
	for (string word : *pkeys)
		cout << word << " " << st->get(word) << endl;

	// print keys in order using select
	cout << "Testing select" << endl;
	cout << "-----------------" << endl;
	for (int i = 0; i < st->size(); i++)
		cout << i << " " << st->select(i) << endl;

	// test rank, floor, ceiling
	cout << "Testing key rank(key) floor(key) ceil(key)" << endl;
	cout << "--------------------------------" << endl;

	string s;
	for (char i = 'A'; i <= 'Z'; i++) {
		stringstream stream;
		stream << i;
		s = stream.str();
		cout << s << " " << st->rank(s) << " " << st->floor(s) << " " << st->ceiling(s) << endl;
	}


	// test range search and range count
	string from[] = { "A", "Z", "X", "0", "B", "C" };
	string to[] = { "Z", "A", "X", "Z", "G", "L" };
	cout << ("range search") << endl;
	cout << ("-------------------") << endl;
	for (int i = 0; i < sizeof(from) / sizeof(string); i++) {
		cout << from[i] << "-" << to[i] << st->size(from[i], to[i]) << endl;
		for (string s : *st->keys(from[i], to[i]))
			cout << s + " " << endl;
	}

	// 	 delete the smallest keys
	for (int i = 0; i < st->size() / 2; i++) {
		st->deleteMin();
	}
	cout << "After deleting the smallest " << st->size() / 2 << "keys" << endl;
	cout << "--------------------------------" << endl;
	for (string s : *st->keys())
		cout << s + " " << st->get(s) << endl;

	// delete all the remaining keys
	while (!st->isEmpty()) {
		st->del(st->select(st->size() / 2));
	}
	cout << "After deleting the remaining keys" << endl;
	cout << "--------------------------------" << endl;
	for (string s : *st->keys())
		cout << s + " " << st->get(s) << endl;

	cout << "After adding back the keys" << endl;
	cout << "--------------------------------" << endl;
	for (int i = 0; i < sizeof(keys) / sizeof(string); i++)
		st->put(keys[i], i);
	for (string s : *st->keys())
		cout << s + " " << st->get(s) << endl;
}

template class RedBlackBST<string, int>;