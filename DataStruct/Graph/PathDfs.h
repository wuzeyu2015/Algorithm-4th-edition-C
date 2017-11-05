#ifndef _PATHDFS_H
#define _PATHDFS_H

#include <iostream>
#include <cassert>
#include <stack>
using namespace std;


template <typename Graph>
class PathDfs{

private:
	Graph &G;
	bool *visited;//数组记录节点是否已经被访问
	int *from;	  //from[i]标记i的上一个节点
	int s;		  //路径起始点

	void dfs( int v ){
		visited[v] = true;
		Graph::adjIterator itor(G, v);
		for(int i = itor.begin(); !itor.end(); i = itor.next()){
			if( !visited[i] ){
				from[i] = v;//记录i的上一个节点
				dfs(i);		
			}
		}
	}
public:
	PathDfs(Graph &graph, int s): G(graph){
		visited = new bool[G.V()];
		from = new int[G.V()];
		this->s = s;
		for(int i = 0; i < G.V(); i++){
			visited[i] = false;
			from[i] = -1;
		}
			dfs(s);//提取s顶点所在的联通分量里面所有点的from信息
}

	~PathDfs(){
		delete []visited;
		delete []from;
	}

	bool hasPath(int w){
		assert( w >= 0 && w < G.V() );
		return visited[w];
	}
	void FindPath(int w, vector<int> &vec){

		stack<int> s;

		int p = w;
		while( p != -1 ){
			s.push(p);
			p = from[p];
		}

		vec.clear();
		while( !s.empty() ){
			vec.push_back( s.top() );
			s.pop();
		}
	}
	void showPath(int w){
		vector<int> vec;
		FindPath( w , vec );
		for( int i = 0 ; i < vec.size() ; i ++ ){
			cout<<vec[i];
			if( i == vec.size() - 1 )
				cout<<endl;
			else
				cout<<" -> ";
		}
	}
};

#endif //_PATHDFS_H
