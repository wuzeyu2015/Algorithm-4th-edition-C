#include "stdafx.h"


//递归实现，没有考虑省略不相关字符和大小写区分
bool isPalindrome(string s) {
	if (s.size() <= 1)
	{
		return true;
	}
	else if (s[0] == s[s.size() - 1])
	{
		s.pop_back();
		s.erase(0, 1);
		return isPalindrome(s);
	}
	else
		return false;
}

void test_125(){
 
	bool i = isPalindrome("a.");
}