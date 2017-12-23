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

public:
	Value get(Key key);
	void put(Key key, Value val);
	bool contains(Key key);
	vector<Key>* keys();//∂¡»°keys
	int size();
	bool isEmpty();

	static void main(int minLen);

private:
	Key* keyarr;
	Value* valarr;
	int N;
	int rank(Key key);
};


