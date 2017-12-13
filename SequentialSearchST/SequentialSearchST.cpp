#include "stdafx.h"
#include "SequentialSearchST.h"

template<class Key, class Value>
SequentialSearchST<Key, Value>::SequentialSearchST()
{
	pfirst = NULL;
}

template<class Key, class Value>
SequentialSearchST<Key, Value>::~SequentialSearchST()
{
}

template<class Key, class Value>
void SequentialSearchST<Key, Value>::put(Key key, Value val){
	for(Node* pNode = pfirst; pNode != NULL; pNode = pNode->next){
		if(pNode->key == key){
			pNode->val = val;
			return;
		}
	}
	pfirst = new Node(key, val, pfirst);
}

template<class Key, class Value>
Value SequentialSearchST<Key, Value>::get(Key key) {
	for (Node* pNode = pfirst; pNode != NULL; pNode = pNode->next) {
		if (pNode->key == key) {
			return pNode->val;
		}
	}
	return NULL;
}
template<class Key, class Value>
bool SequentialSearchST<Key, Value>::contains(Key key){
	for (Node* pNode = pfirst; pNode != NULL; pNode = pNode->next) {
		if (pNode->key == key) {
			return true;
		}
	}
	return false;
}

template<class Key, class Value>
vector<Key>* SequentialSearchST<Key, Value>::keys() {
	vector<Key>* pQueue = new vector<Key>();
	for (Node* pNode = pfirst; pNode != NULL; pNode = pNode->next)
		pQueue->push_back(pNode->key);
	return pQueue;
}
template class SequentialSearchST<string, int>;