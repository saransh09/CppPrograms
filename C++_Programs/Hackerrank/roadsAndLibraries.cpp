#include <bits/stdc++.h>
using namespace std;

class Graph{
	vector<vector<int> > adjList;
public:
	Graph(){}
	int V() const {
		return adjList.size();
	}
	void addEdge(int src, int dest){
		int max = src > dest ? src : dest;
		if(max+1>V()){
			adjList.resize(max+1);
		}
		auto it = find(adjList[src].begin(),adjList[src].end(),dest);
		if(it!=adjList[src].end()){
			throw "You are inserting the edge again";
		}
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	void BFS(int s, vector<int> & traverse){
		vector<bool> color(V(),'w');
		vector<int> d(V(),INT_MAX);
		vector<int> parent(V(),INT_MIN);
		color[s]='g';
		d[s]=0;
		parent[s]=-1;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty()){
			int curr = Q.front();
			Q.pop();
			traverse.push_back(curr);
			auto it = adjList[curr].begin();
			while(it!=adjList[curr].end()){
				if(color[*it]=='w'){
					color[*it]='g';
					d[*it]=d[curr]+1;
					parent[*it]=curr;
					Q.push(*it);
				}
				color[curr]='b';
				it++;
			}
		}
	}
	void DFS(){
		vector<bool> visited(V(),false);
		vector<int> traverse;
		for(int i=0;i<V();i++){
			if(visited[i]==false){
				DFSUtil(i, visited, traverse);
			}
		}
	}
	void DFSUtil(int s,vector<bool> & visited, vector<int> & traverse){
		visited[s]=true;
		traverse.push_back(s);
		auto it = adjList[s].begin();
		while(it!=adjList[s].end()){
			if(visited[*it]!=true){
				DFSUtil(*it, visited, traverse);
			}
			it++;
		}
	}
};

int main() {

	return 0;	
}