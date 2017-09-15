#include "stdafx.h"
#include<iostream>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>
#include <stdio.h>
using namespace std;

namespace UF1{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->id = new int[n];
			for(int i = 0; i < n; i++){
				id[i] = i;
			}
		}
		~UnionFind(){
			delete [] id;
		}
		//合并p、q元素所在的两个集合O(n)
		void UnionElements(int p, int q){
			int pID = find(p);
			int qID = find(q);
			if (pID == qID)
				return;
			for(int i = 0; i < count; i++){
				if(id[i] == qID)
					id[i] = pID;
			}
		}
		//查找元素所在集合O(1)
		int find(int p){
			assert(p >=0 && p < count);
			return id[p];
		}

		//是否在同一个集合O(1)
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//元素个数
		int* id;//索引i就是集合中的元素，索引值parent[i]就是元素所在集合
	};
}
namespace UF2{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
		}
		~UnionFind(){
			delete [] parent;
		}
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			parent[pRoot] = qRoot;
		}
		int find(int p){
			assert(p >=0 && p < count);
			while(parent[p] != p)
				p = parent[p];
			return p;
		}

		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//元素个数
		int* parent;//索引i就是集合中的元素，索引值parent[i]是父节点元素，parent[i] == i的时候，表示已经到达根节点（所在集合）
	};
}
namespace UF3{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			this->size = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
			for(int i = 0; i < n; i++){
				size[i] = 1;
			}
		}
		~UnionFind(){
			delete [] parent;
			delete [] size;
		}
		//合并p、q元素所在的两个集合
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			if(size[pRoot] > size[qRoot]){
				parent[qRoot] = pRoot;
				size[pRoot] += size[qRoot];
			}
			else{
				parent[pRoot] = qRoot;
				size[qRoot] += size[pRoot];
			}
		}
		//查找元素所在集合
		int find(int p){
			assert(p >=0 && p < count);
			while(parent[p] != p)
				p = parent[p];
			return p;
		}

		//是否在同一个集合
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//元素个数
		int* parent;//索引i就是集合中的元素，索引值parent[i]是父节点元素，parent[root] == root的时候，root表示根节点（所在集合）
		int* size;//size[root]是这个集合的元素个数，合并的时候，小集合连接在大集合根节点下可以优化的深度
	};
}
namespace UF4{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			this->rank = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
			for(int i = 0; i < n; i++){
				rank[i] = 1;
			}
		}
		~UnionFind(){
			delete [] parent;
			delete [] rank;
		}
		//合并p、q元素所在的两个集合
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			if(rank[pRoot] > rank[qRoot])
				parent[qRoot] = pRoot;
			else if(rank[pRoot] < rank[qRoot])
				parent[pRoot] = qRoot;
			else{
				//两个集合深度相同的情况下，合并后的深度才会比原来增加1
				parent[qRoot] = pRoot;
				rank[pRoot] += 1;
			}
		}
		//查找元素所在集合
		int find(int p){
			assert(p >=0 && p < count);
			while(parent[p] != p)
				p = parent[p];
			return p;
		}

		//是否在同一个集合
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//元素个数
		int* parent;//索引i就是集合中的元素，索引值parent[i]是父节点元素，parent[root] == root的时候，root表示根节点（所在集合）
		int* rank;//rank[root]是这个集合的深度，合并的时候，浅的集合连接到较深的集合的根节点
	};
}
namespace UF5{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			this->rank = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
			for(int i = 0; i < n; i++){
				rank[i] = 1;
			}
		}
		~UnionFind(){
			delete [] parent;
			delete [] rank;
		}
		//合并p、q元素所在的两个集合
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			if(rank[pRoot] > rank[qRoot])
				parent[qRoot] = pRoot;
			else if(rank[pRoot] < rank[qRoot])
				parent[pRoot] = qRoot;
			else{
				//两个集合深度相同的情况下，合并后的深度才会比原来增加1
				parent[qRoot] = pRoot;
				rank[pRoot] += 1;
			}
		}
		//查找元素p所在集合，过程中进行路径压缩
		int find(int p){
			assert(p >=0 && p < count);
			while(parent[p] != p){
				parent[p] = parent[parent[p]]; 
					p = parent[p];
			}

			return p;
		}

		//是否在同一个集合
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//元素个数
		int* parent;//索引i就是集合中的元素，索引值parent[i]是父节点元素，parent[root] == root的时候，root表示根节点（所在集合）
		int* rank;//rank[root]是这个集合的深度，合并的时候，浅的集合连接到较深的集合的根节点
	};
}
namespace UF6{

	class UnionFind
	{
	public:
		UnionFind(int n){
			this->count = n;
			this->parent = new int[n];
			this->rank = new int[n];
			for(int i = 0; i < n; i++){
				parent[i] = i;
			}
			for(int i = 0; i < n; i++){
				rank[i] = 1;
			}
		}
		~UnionFind(){
			delete [] parent;
			delete [] rank;
		}
		//合并p、q元素所在的两个集合
		void UnionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);
			if (pRoot == qRoot)
				return;
			if(rank[pRoot] > rank[qRoot])
				parent[qRoot] = pRoot;
			else if(rank[pRoot] < rank[qRoot])
				parent[pRoot] = qRoot;
			else{
				//两个集合深度相同的情况下，合并后的深度才会比原来增加1
				parent[qRoot] = pRoot;
				rank[pRoot] += 1;
			}
		}
		//查找元素p所在集合，过程中进行路径压缩(每个节点都递归连接到根节点)
		int find(int p){
			assert(p >=0 && p < count);
			if(parent[p] != p){
				parent[p] = find(parent[p]);
			}
			return parent[p];
		}

		//是否在同一个集合
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
	private:
		int count;//元素个数
		int* parent;//索引i就是集合中的元素，索引值parent[i]是父节点元素，parent[root] == root的时候，root表示根节点（所在集合）
		int* rank;//rank[root]是这个集合的深度，合并的时候，浅的集合连接到较深的集合的根节点
	};
}
namespace UnionFindTestHelper{
	void testUF1(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF1::UnionFind uf1 = UF1::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF1, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF2(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF2::UnionFind uf1 = UF2::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF2, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF3(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF3::UnionFind uf1 = UF3::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF3, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF4(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF4::UnionFind uf1 = UF4::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF4, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF5(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF5::UnionFind uf1 = UF5::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF5, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
	void testUF6(int n){
		srand(time(NULL));
		time_t istart = clock();
		UF6::UnionFind uf1 = UF6::UnionFind(n);
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.UnionElements(a, b);
		}
		for(int i = 0; i < n; i++){
			int a = rand()%n;
			int b = rand()%n;
			uf1.isConnected(a, b);
		}
		time_t iend = clock();
		cout<<"UF6, "<<2*n<<" ops, "<<double(iend - istart)/CLOCKS_PER_SEC<<" s"<<endl;
	}
}
