#include "stdafx.h"


void addNextWords(string word, set<string>& wordDict, queue<string>& toVisit) {
	wordDict.erase(word);
	for (int p = 0; p < (int)word.length(); p++) {
		char letter = word[p];
		for (int k = 0; k < 26; k++) { 
			word[p] = 'a' + k;
			if (wordDict.find(word) != wordDict.end()) {
				toVisit.push(word);
				wordDict.erase(word);
			}
		}
		word[p] = letter;
} 
int ladderLength(string beginWord, string endWord, set<string>& wordDict) {
	wordDict.insert(endWord);
	queue<string> toVisit;
	addNextWords(beginWord, wordDict, toVisit);
	int dist = 2;
	while (!toVisit.empty()) {
		int num = toVisit.size();
		for (int i = 0; i < num; i++) {
			string word = toVisit.front();
			toVisit.pop();
			if (word == endWord) return dist;
			addNextWords(word, wordDict, toVisit);
		}
		dist++;
	}
}


void test_127(){

	//ladderLength(isValid("()[]{}"));
}