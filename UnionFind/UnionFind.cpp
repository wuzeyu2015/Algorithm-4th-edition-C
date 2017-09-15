// UnionFind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UnionFind.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 1000000;

	// Quick Find
	//UnionFindTestHelper::testUF1(n);

	// Quick Union
	//UnionFindTestHelper::testUF2(n);

	// Quick Union + sz
	UnionFindTestHelper::testUF3(n);
 
 	// Quick Union + rank
 	UnionFindTestHelper::testUF4(n);

 	// Quick Union + rank + path compression
 	UnionFindTestHelper::testUF5(n);

	// Quick Union + rank + path compression(recursion)
	UnionFindTestHelper::testUF6(n);
	system("pause");
	return 0;
}

