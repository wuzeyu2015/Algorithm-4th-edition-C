#pragma once

#include "stdafx.h"


string multiply(string num1, string num2) {
	string rnum1 = num1;
	string rnum2 = num2;
	vector<int> ires(num1.size() +num2.size(), 0);
	//反转字符数组，从数组num[0]（个位数）开始计算
	reverse(rnum1.begin(), rnum1.end());
	reverse(rnum2.begin(), rnum2.end());
	//模拟手工计算，不进位，计算出每个位置的数字
	for (int i1 = 0; i1 < rnum1.size(); i1++) {
		for (int i2 = 0; i2 < rnum2.size(); i2++) {
			ires[i1 + i2] += (rnum1[i1] - 48)*(rnum2[i2] - 48);
		}
	}
	//进位操作
	for (int i = 0; i < ires.size() - 1; i++) {
		ires[i + 1] += ires[i] / 10;
		ires[i] = ires[i] % 10;
	}
	//忽略为0的高位
	while (ires.back() == 0 && !ires.empty()) {
		ires.pop_back();
	}
	if (ires.empty())
		ires.push_back(0);
	//反转恢复字符串
	string res;
	for (int i = 0; i < ires.size(); i++) {
		res.push_back(ires[i] + 48);
	}
	reverse(res.begin(), res.end());
	return res;
}

void test_043() {
	TreeNode* p = new TreeNode(0);
	p->left = NULL;
	p->right = NULL;
	string s = multiply("33", "33");
}