#include "stdafx.h"
#include "BinarySearchST.h"

template<class Key, class Value>
BinarySearchST<Key, Value>::BinarySearchST(int cap)
{
	keyarr = new Key[cap];
	memset(keyarr, 0, cap * sizeof(Key));
	valarr = new Value[cap];
	memset(valarr, 0, cap * sizeof(Value));
	N = 0;
}

template<class Key, class Value>
BinarySearchST<Key, Value>::~BinarySearchST()
{
	delete keyarr;
	keyarr = NULL;
	delete valarr;
	valarr = NULL;
}

template<class Key, class Value>
void BinarySearchST<Key, Value>::put(Key key, Value val) {
	int i = rank(key);
	if (i < N && keyarr[i] == key){
		valarr[i] = val;
		return;
	}
	for (int j = N; j > i; j--) {
		keyarr[j] = keyarr[j - 1];
		valarr[j] = valarr[j - 1];
	}
	keyarr[i] = key;
	valarr[i] = val;
	N++;
		
}

template<class Key, class Value>
Value BinarySearchST<Key, Value>::get(Key key) {
	int i = rank(key);
	if (i < N && keyarr[i] == key)
		return valarr[i];
	else
		return NULL;
}
template<class Key, class Value>
bool BinarySearchST<Key, Value>::contains(Key key) {
	for (int i = 0; i < N; i++) {
		if (keyarr[i] == key)
			return true;
	}
	return false;
}
template<class Key, class Value>
vector<Key>* BinarySearchST<Key, Value>::keys() {
	vector<Key>* pQueue = new vector<Key>();
	for (int i = 0; i < N; i++){
		pQueue->push_back(keyarr[i]);
	}
	return pQueue;
}
template<class Key, class Value>
int BinarySearchST<Key, Value>::rank(Key key) {
	int lo = 0;
	int hi = N - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (keyarr[mid] == key)
			return mid;
		else if (keyarr[mid] > key)
			hi = mid - 1;
		else if (keyarr[mid] < key)
			lo = mid + 1;
	}
	return lo;
}
template<class Key, class Value>
int BinarySearchST<Key, Value>::size() {
	return N;
}
template<class Key, class Value>
bool BinarySearchST<Key, Value>::isEmpty() {
	return size() == 0;
}

template class BinarySearchST<string, int>;

//测试入口函数
template<class Key, class Value>
void BinarySearchST<Key, Value>::testmain(int minLen) {

	BinarySearchST<string, int>* st = new BinarySearchST<string, int>(1000000);

	ifstream ifs("tale.txt");//初始化一个输入流
	string read;
	while (getline(ifs, read, ' ')) //以‘ ’为分割（读取单词）  
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
	for (string cur : *st->keys()) {
		if (st->get(cur) > st->get(maxfreqstring))
			maxfreqstring = cur;
	}
	cout << "highest frequency:" << maxfreqstring << endl;
	cout << "count:" << st->get(maxfreqstring) << endl;
}