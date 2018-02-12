#include "stdafx.h"
bool isMatch(char comp1, char comp2) {
	if (comp1 == ')')
		return comp2 == '(';
	else if (comp1 == ']')
		return comp2 == '[';
	else if (comp1 == '}')
		return comp2 == '{';
}
bool isValid(string s) {
	stack<char> cstack;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
			cstack.push(s[i]);
		}
		else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
			if (cstack.empty())
				return false;
			if (isMatch(s[i], cstack.top()))
				cstack.pop();
			else
				return false;
		}
	}
	return cstack.empty();
}
void test_20() {
	assert(isValid("()[]{}"));
}
