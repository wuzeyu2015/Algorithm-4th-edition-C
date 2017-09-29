#include "stdafx.h"

/* 
动态规划法：
dp[0] = 0 
dp[1] = dp[0]+1 = 1
dp[2] = dp[1]+1 = 2
dp[3] = dp[2]+1 = 3
dp[4] = Min{ dp[4-1*1]+1, dp[4-2*2]+1 } 
	  = Min{ dp[3]+1, dp[0]+1 } 
	  = 1				
dp[5] = Min{ dp[5-1*1]+1, dp[5-2*2]+1 } 
	  = Min{ dp[4]+1, dp[1]+1 } 
	  = 2
dp[13] = Min{ dp[13-1*1]+1, dp[13-2*2]+1, dp[13-3*3]+1 } 
	   = Min{ dp[12]+1, dp[9]+1, dp[4]+1 } 
	   = 2
...
dp[n] = Min{ dp[n - i*i] + 1 },  n - i*i >=0 && i >= 1
*/
int numSquares(int n) {
	vector<int> dp(1,0);//初始化dp[0]
	for (int i = 1;i <= n ; i++) {
		int m = dp.size(), squares = INT_MAX;
		for (int j=1; j*j<=m; ++j){
			squares = min(squares, dp[m-j*j] + 1);
		}
		dp.push_back(squares);
	}
	return dp[n];
}

void test_279(){
	numSquares(5);
}


/*leetcode discussBFS解法(Queue)*/
// class Solution 
// {
// public:
// 	int numSquares(int n) 
// 	{
// 		if (n <= 0)
// 		{
// 			return 0;
// 		}
// 
// 		// perfectSquares contain all perfect square numbers which 
// 		// are smaller than or equal to n.
// 		vector<int> perfectSquares;
// 		// cntPerfectSquares[i - 1] = the least number of perfect 
// 		// square numbers which sum to i.
// 		vector<int> cntPerfectSquares(n);
// 
// 		// Get all the perfect square numbers which are smaller than 
// 		// or equal to n.
// 		for (int i = 1; i*i <= n; i++)
// 		{
// 			perfectSquares.push_back(i*i);
// 			cntPerfectSquares[i*i - 1] = 1;
// 		}
// 
// 		// If n is a perfect square number, return 1 immediately.
// 		if (perfectSquares.back() == n)
// 		{
// 			return 1;
// 		}
// 
// 		// Consider a graph which consists of number 0, 1,...,n as
// 		// its nodes. Node j is connected to node i via an edge if  
// 		// and only if either j = i + (a perfect square number) or 
// 		// i = j + (a perfect square number). Starting from node 0, 
// 		// do the breadth-first search. If we reach node n at step 
// 		// m, then the least number of perfect square numbers which 
// 		// sum to n is m. Here since we have already obtained the 
// 		// perfect square numbers, we have actually finished the 
// 		// search at step 1.
// 		queue<int> searchQ;
// 		for (auto& i : perfectSquares)
// 		{
// 			searchQ.push(i);
// 		}
// 
// 		int currCntPerfectSquares = 1;
// 		while (!searchQ.empty())
// 		{
// 			currCntPerfectSquares++;
// 
// 			int searchQSize = searchQ.size();
// 			for (int i = 0; i < searchQSize; i++)
// 			{
// 				int tmp = searchQ.front();
// 				// Check the neighbors of node tmp which are the sum 
// 				// of tmp and a perfect square number.
// 				for (auto& j : perfectSquares)
// 				{
// 					if (tmp + j == n)
// 					{
// 						// We have reached node n.
// 						return currCntPerfectSquares;
// 					}
// 					else if ((tmp + j < n) && (cntPerfectSquares[tmp + j - 1] == 0))
// 					{
// 						// If cntPerfectSquares[tmp + j - 1] > 0, this is not 
// 						// the first time that we visit this node and we should 
// 						// skip the node (tmp + j).
// 						cntPerfectSquares[tmp + j - 1] = currCntPerfectSquares;
// 						searchQ.push(tmp + j);
// 					}
// 					else if (tmp + j > n)
// 					{
// 						// We don't need to consider the nodes which are greater ]
// 						// than n.
// 						break;
// 					}
// 				}
// 
// 				searchQ.pop();
// 			}
// 		}
// 
// 		return 0;
// 	}
// };
