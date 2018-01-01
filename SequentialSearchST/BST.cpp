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
	if (pnode->key == key) {
		pnode->val = val;
		return pnode;
	}

	else if (pnode->key < key)
		put(pnode->right, key, val);
	else if (pnode->key > key)
		put(pnode->left, key, val);
	else
		pnode->val = val;

}
template<class Key, class Value>
bool BST<Key, Value>::contains(Key key) {
	return get(key) != NULL;
}
template<class Key, class Value>
int BST<Key, Value>::size() {
	return N;
}
template<class Key, class Value>
int BST<Key, Value>::min() {
	return N;
}
template<class Key, class Value>
int BST<Key, Value>::max() {
	return N;
}
template<class Key, class Value>
bool BST<Key, Value>::isEmpty() {
	return N == 0;
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
template class BST<string, int>;



//测试入口函数
template<class Key, class Value>
void BST<Key, Value>::main(int minLen) {

	BST<string, int>* st = new BST<string, int>();

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
void BST<Key, Value>::main2(int minLen) {

	BST<string, int>* st = new BST<string, int>();

	string keys[] = { "S", "E" };
	for (int i = 0; i < sizeof(keys)/sizeof(string); i++)
		st->put(keys[i], i);
	cout << "size = " << st->size() << endl;
	cout << "min = " << st->min() << endl;
	cout << "max = " << st->max() << endl;

	// print keys in order using allKeys()
	cout << "Testing keys()" << endl;
	cout << "--------------------------------"<< endl;
	vector<Key>* pkeys = st->keys();
	for (string word : *pkeys)
		cout << word <<" "<< st->get(word) << endl;

	// print keys in order using select
// 	StdOut.println("Testing select");
// 	StdOut.println("--------------------------------");
// 	for (int i = 0; i < st.size(); i++)
// 		StdOut.println(i + " " + st.select(i));
// 	StdOut.println();
// 
// 	// test rank, floor, ceiling
// 	StdOut.println("key rank floor ceil");
// 	StdOut.println("-------------------");
// 	for (char i = 'A'; i <= 'Z'; i++) {
// 		String s = i + "";
// 		StdOut.printf("%2s %4d %4s %4s\n", s, st.rank(s), st.floor(s), st.ceiling(s));
// 	}
// 	StdOut.println();
// 
// 	// test range search and range count
// 	String[] from = { "A", "Z", "X", "0", "B", "C" };
// 	String[] to = { "Z", "A", "X", "Z", "G", "L" };
// 	StdOut.println("range search");
// 	StdOut.println("-------------------");
// 	for (int i = 0; i < from.length; i++) {
// 		StdOut.printf("%s-%s (%2d) : ", from[i], to[i], st.size(from[i], to[i]));
// 		for (String s : st.keys(from[i], to[i]))
// 			StdOut.print(s + " ");
// 		StdOut.println();
// 	}
// 	StdOut.println();
// 
// 	// delete the smallest keys
// 	for (int i = 0; i < st.size() / 2; i++) {
// 		st.deleteMin();
// 	}
// 	StdOut.println("After deleting the smallest " + st.size() / 2 + " keys");
// 	StdOut.println("--------------------------------");
// 	for (String s : st.keys())
// 		StdOut.println(s + " " + st.get(s));
// 	StdOut.println();
// 
// 	// delete all the remaining keys
// 	while (!st.isEmpty()) {
// 		st.delete(st.select(st.size() / 2));
// 	}
// 	StdOut.println("After deleting the remaining keys");
// 	StdOut.println("--------------------------------");
// 	for (String s : st.keys())
// 		StdOut.println(s + " " + st.get(s));
// 	StdOut.println();
// 
// 	StdOut.println("After adding back the keys");
// 	StdOut.println("--------------------------------");
// 	for (int i = 0; i < n; i++)
// 		st.put(keys[i], i);
// 	for (String s : st.keys())
// 		StdOut.println(s + " " + st.get(s));
// 	StdOut.println();

}