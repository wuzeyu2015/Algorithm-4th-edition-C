#pragma once
#include<iostream>  
#include<fstream>  
#include <string>
#include <vector>
#include <queue>
using namespace std;

template<class Key, class Value>
class BinarySearchST
{
public:
	BinarySearchST(int cap);
	~BinarySearchST();

private:
	Key* keyarr;
	Value* val;
	int N;
	int rank(Key key);
public:
	Value get(Key key);
	void put(Key key, Value val);
	bool contains(Key key);
	int size();
	bool isEmpty();

};


