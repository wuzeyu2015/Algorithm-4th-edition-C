#include "stdafx.h"
#include "BinarySearchST.h"

template<class Key, class Value>
BinarySearchST<Key, Value>::BinarySearchST(int cap)
{
	key = new Key[cap];
	memset(key, 0, cap*sizeof(Key));
	val = new Value[cap];
	memset(val, 0, cap*sizeof(Value));
	N = 0;
}

template<class Key, class Value>
BinarySearchST<Key, Value>::~BinarySearchST()
{
	delete key;
	key = NULL;
	delete val;
	val = NULL;
}

template<class Key, class Value>
void BinarySearchST<Key, Value>::put(Key key, Value val) {

}

template<class Key, class Value>
Value BinarySearchST<Key, Value>::get(Key key) {

	return NULL;
}
template<class Key, class Value>
bool BinarySearchST<Key, Value>::contains(Key key) {

	return false;
}

template<class Key, class Value>
vector<Key>* BinarySearchST<Key, Value>::keys() {
	vector<Key>* pQueue = new vector<Key>();

	return pQueue;
}
template<class Key, class Value>
int BinarySearchST<Key, Value>::rank(Key key) {
	int lo = 0;
	int hi = N - 1;
	while (lo <= hi) {
		int mid = lo + hi / 2;
		if (key[mid] = key)
			return val[mid];
		else if (key[mid] > key)
			hi = mid;
		else if (key[mid] <= key)
			lo = mid;
	}
}


template class BinarySearchST<string, int>;