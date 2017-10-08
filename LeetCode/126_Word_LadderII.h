#include "stdafx.h"

// 0、注意进入循环之前第一个元素的构建；
// 1、BFS中queue是必须的数据结构；
// 2、BFS循环永远是：外部循环（每层） + 内部循环（循环次数是变量），访问队首元素、压入后续元素；
// 3、注意时间复杂度分析以及15行的优化对复杂度的影响；
// 4、res为最短路径；

void NextLevel(string beginWord, set<string>& wordDict, queue<string>& toVisit) {
	string strtemp = beginWord;
	wordDict.erase(beginWord);
	
	for (int i = 0; i < strtemp.size(); i++)
	{
		for (char c = 'a'; c <= 'z'; c++)
		{
			beginWord[i] = c;				//穷举可能的字符串
			if(wordDict.find(beginWord) != wordDict.end()){
				toVisit.push(beginWord);	//寻找与beginWord相邻的字符串，然后把它们放进队列toVisit
				wordDict.erase(beginWord);	//必须的性能优化，否则超时
			}		
		}
		beginWord = strtemp;			    //还原beginWord
	}
}

vector <vector <string>> ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	set<string> wordDict(wordList.begin(), wordList.end());
	vector <vector <string>> res(0, vector <string>());
	int iLevel = -1;
	queue<string> toVisit;
	toVisit.push(beginWord);				//构建第一层
	while (!toVisit.empty())
	{
		iLevel++;
		int curLevel = toVisit.size();
		for(int i = 0; i < curLevel; i++){
			beginWord = toVisit.front();
			toVisit.pop();
			if(beginWord == endWord)
				return res;
			NextLevel(beginWord, wordDict, toVisit);
		}
	}
	return res;
}



void test_127(){
	vector<string> wordDict;
	wordDict.push_back("hot");
	wordDict.push_back("dot");
	wordDict.push_back("dog");
	wordDict.push_back("lot");
	wordDict.push_back("log");
	wordDict.push_back("cog");
	int i = ladderLength("hit", "cog", wordDict);
}

