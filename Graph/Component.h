#ifndef _COMPONENTS_COMPONENTS_H
#define _COMPONENTS_COMPONENTS_H

#include <iostream>
#include <cassert>
using namespace std;


template <typename Graph>
class Component{

private:
	Graph &G;
	bool *visited;//数组记录节点是否已经被访问
	int ccount;//联通分量的数量
	int *id;//数组记录节点所属联通分量的编号

	void dfs( int v ){
		visited[v] = true;
		id[v] = ccount;
		Graph::adjIterator itor(G, v);
		for(int i = itor.begin(); !itor.end(); i = itor.next()){
			if( !visited[i] )
				dfs(i);
			}
	}
public:
	Component(Graph &graph): G(graph){
		ccount = 0;
		visited = new bool[G.V()];
		id = new int[G.V()];
		for(int i = 0; i < G.V(); i++){
			visited[i] = false;
			id[i] = -1;
		}
		for(int i = 0; i < G.V(); i++){
			if(!visited[i]){
			   dfs(i);
			   ccount++;
			}

		}
	}

	~Component(){
		delete []visited;
		delete []id;
	}
	int count(){
		return ccount;
	}
	bool isConnected( int v , int w ){
		assert( v >= 0 && v < G.V() );
		assert( w >= 0 && w < G.V() );
		return (id[v] == id[w]);
	}
};

#endif //_COMPONENTS_COMPONENTS_H
