#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class Key, class Value>
class SequentialSearchST
{
public:
	SequentialSearchST();
	~SequentialSearchST();

private:
	class Node
	{
	public:
		Node(Key key, Value val, Node* next){
			this->key = key;
			this->val = val;
			this->next = next;
		}
		Key key;
		Value val;
		Node* next;
	};
	Node* pfirst;
public:
	Value get(Key key);
	void put(Key key, Value val);
	bool contains(Key key);
	vector<Key>* keys();//返回key的集合，用vector

};


