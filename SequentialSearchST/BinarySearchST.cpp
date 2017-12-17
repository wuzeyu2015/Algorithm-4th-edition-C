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

	return false;
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