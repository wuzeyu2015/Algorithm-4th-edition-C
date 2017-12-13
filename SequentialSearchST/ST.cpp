// SequentialSearchST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SequentialSearchST.h"

void testSequentialSearchST(int minLen) {

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
	string maxword = " ";
	st->put(maxword, 0);
	for(string word : *st->keys()){
		if (st->get(word) > st->get(maxword))
			maxword = word;
	}
	cout << maxword << st->get(maxword);
}

int main()
{
	testSequentialSearchST(8);
	system("pause");
    return 0;
}

