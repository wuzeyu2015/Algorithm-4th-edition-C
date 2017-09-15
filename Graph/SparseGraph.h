#ifndef _SPARSEGRAPH_H
#define _SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class SparseGraph{
public:
	//构造一个拥有n个点，边为空，边的有向性可选的图
	SparseGraph(int n, bool directed){
		this->directed = directed;
		this->n = n;
		this->m = 0;
		for(int i = 0; i < n; i++){
			g.push_back(vector<int>());
		}
	}
	~SparseGraph(){
	}
	//[0, n)范围两个顶点之间添加一个边
	void addEdge(int v, int w){
		assert( v >= 0 && v < n);
		assert( w >= 0 && w < n);

		g[v].push_back(w);
		//自环边情况下不再重复push
		if(!directed && v != w)
			g[w].push_back(v);

		m++;
	}
	//相比邻接矩阵，邻接表的hasEdge复杂度提高了，所以addEdge里面不处理平行边（用例里面没有平行边情况）
	bool hasEdge(int v, int w){
		assert( v >= 0 && v < n);
		assert( w >= 0 && w < n);
		for(int i = 0; i < g[v].size(); i++){
			if(g[v][i] == w)
				return true;
		}
			return false;
	}

	int V(){
		return n;
	}
	int E(){
		return m;
	}

	void show(){

		for( int i = 0 ; i < n ; i ++ ){
			cout<<"vertex "<<i<<":\t";
			for( int j = 0 ; j < g[i].size() ; j ++ )
				cout<<g[i][j]<<"\t";
			cout<<endl;
		}
	}
private:
	int n;//顶点数
	int m;//边数
	bool directed;//是否是有向图
	vector<vector<int>> g;//邻接表存储方式（适合稀疏图），g[i]数组表示i顶点连接了哪些顶点
///////////////////////////////////////////////////////////////
public:
	class adjIterator{

		int index;
		int v;
		SparseGraph& G;

	public:
		adjIterator(SparseGraph& graph, int v):G(graph){
			this->v = v;
			index = 0;
		}
		~adjIterator(){
		}
		int begin(){
			if(G.g[v].size())
				return G.g[v][0];
			return -1;
		}
		int next(){
			if(++index < G.g[v].size())
			return G.g[v][index];			
		}
		bool end(){
			return (index >= G.g[v].size());
		}
	};
};

#endif _SPARSEGRAPH_H
//1、如果需要判断平行边情况，又不想在addEdge里面添加判断导致性能损耗，可以考虑全部添加完之后进行平行边的统一处理？