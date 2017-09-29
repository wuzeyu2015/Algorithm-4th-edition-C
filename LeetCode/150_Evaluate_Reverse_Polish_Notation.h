#include "stdafx.h"

int calculate(int x, int y, string mathOpt){
	if(mathOpt == "+")
		return x + y;
	else if(mathOpt == "-")
		return x - y;
	else if(mathOpt == "*")
		return x * y;
	else if(mathOpt == "/")
		return x / y;
}
int evalRPN(vector<string>& tokens){
	stack<int> istack; 
	for(int i = 0; i < tokens.size(); i++){
		if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
			int y = istack.top();
			istack.pop();
			int x = istack.top();
			istack.pop();
			int z = calculate(x, y, tokens[i]);
			//把结果放回栈
			istack.push(z);
		}
		else
			istack.push(atoi(tokens[i].c_str()));
	}
	return istack.top();
}

void test_150(){
	string sarray[] = {"2", "1", "+", "3", "*"};
	vector<string> svector(sarray, sarray + 5);
	evalRPN(svector);
}

