#include "stdafx.h"


string simplifyPath(string path) {
	stack<string> sstack;
	stack<string> sstacktmp;
	string tmp;
	string sret;
	stringstream ss(path);
	while(getline(ss, tmp, '/')){
		//冗余字符情况："/a//b/c"
		if(tmp == "." || tmp == "")
			continue;
		else if(tmp == ".."){
			//已经到了根目录的情况
			if(!sstack.empty())
				sstack.pop();
		}
		else //正常盘符入栈
			sstack.push(tmp);
	}
	//使用c++ 11的for range就可以直接从栈底部访问不需要sstacktmp
	while(!sstack.empty()){
		sstacktmp.push(sstack.top());
		sstack.pop();
	}
	while(!sstacktmp.empty()){
		sret += "/" + sstacktmp.top();
		sstacktmp.pop();
	}
	return sret.empty()? "/" : sret;
}

void test_71(){
	simplifyPath("/..");
}