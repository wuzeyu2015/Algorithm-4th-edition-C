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

//测试入口函数
template<class Key, class Value>
void SequentialSearchST<Key, Value>::main(int minLen) {

	SequentialSearchST<string, int>* st = new SequentialSearchST<string, int>();

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