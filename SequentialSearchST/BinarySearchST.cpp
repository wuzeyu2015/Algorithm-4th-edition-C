#include "stdafx.h"
#include "BinarySearchST.h"

template<class Key, class Value>
BinarySearchST<Key, Value>::BinarySearchST(int cap)
{
	key = new Key[cap];
	val = new Value[cap];
}

template<class Key, class Value>
BinarySearchST<Key, Value>::~BinarySearchST()
{
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
template class BinarySearchST<string, int>;