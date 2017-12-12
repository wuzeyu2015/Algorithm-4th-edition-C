#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
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

};


