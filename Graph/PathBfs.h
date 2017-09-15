#ifndef _PATHBFS_H
#define _PATHBFS_H

#include <iostream>
#include <cassert>
#include <stack>
#include <queue>
using namespace std;


template <typename Graph>
class PathBfs{

private:
	Graph &G;
	bool *visited;//数组记录节点是否已经被访问
	int *from;	  //from[i]标记i的上一个节点
	int s;		  //路径起始点
	int *order;	  //order[i]节点i的无权长度

public:

	PathBfs(Graph &graph, int s):G(graph){

		// 算法初始化
		assert( s >= 0 && s < graph.V() );
		this->s = s;
		visited = new bool[graph.V()];
		from = new int[graph.V()];
		order = new int[graph.V()];
		for( int i = 0 ; i < graph.V() ; i ++ ){
			visited[i] = false;
			from[i] = -1;
			order[i] = -1;
		}

		queue<int> q;
		// 无向图最短路径算法
		q.push( s );
		visited[s] = true;
		order[s] = 0;
		while( !q.empty() ){
			int v = q.front();
			q.pop();
			Graph::adjIterator adj(G, v);
			for( int i = adj.begin() ; !adj.end() ; i = adj.next() )
				if( !visited[i] ){
					q.push(i);//已经入队的节点不能重复入队，保证了每个节点记录路径的唯一性（最短那条）
					visited[i] = true;
					from[i] = v;//记录i的上一个节点
					order[i] = order[v] + 1;//记录i到s的距离
				}
		}
	}
	~PathBfs(){
		delete []visited;
		delete []from;
		delete []order;
	}

	bool hasPath(int w){
		assert( w >= 0 && w < G.V() );
		return visited[w];
	}
	void FindPath(int w, vector<int> &vec){
		assert( w >= 0 && w < G.V() );
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
	int length(int w){
		assert( w >= 0 && w < G.V() );
		return order[w];
	}
};

#endif //_PATHBFS_H
