#include <bits/stdc++.h>
using namespace std;

class Graph{
	vector<vector<int> > adjList;
public:
	Graph() {}
	int V() {
		return adjList.size();
	}
	void addEdge(int src, int dest){
		int max = src > dest ? src : dest;
		if(max > V()) adjList.resize(max+1);
		auto it = find(adjList[src].begin(),adjList[src].end(),dest);
		if(it!=adjList[src].end()) throw "You are inserting the edge again";
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	void BFS(int s, vector<int> & traverse){
		vector<char> color(V(),'w');
		vector<int> d(V(),INT_MIN);
		vector<int> parent(V(),INT_MAX);
		color[s]='g';
		d[s]=0;
		parent[s]=-1;
		queue<int> q;
		q.push(s);
		while(!q.empty()){
			int curr = q.front();
			q.pop();
			traverse.push_back(curr);
			auto it = adjList[curr].begin();
			while(it!=adjList[curr].end()){
				if(color[*it]=='w'){
					color[*it]='g';
					d[*it]=d[curr]+1;
					parent[*it]=curr;
					q.push(*it);
				}
				color[*it]='b';
				it++;
			}
		}
	}
	void DFS() {
		vector<bool> visited(V(),false);
		vector<int> traverse;
		for(int i=0;i<V();i++){
			if(visited[i]==false) DFSUtil(i,visited,traverse);
		}
	}
private:
	void DFSUtil(int s, vector<bool> & visited, vector<int> & traverse){
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
public:
	bool isCyclic(){
		vector<bool> visited(V(),false);
		vector<bool> recStack(V(),false);
		for(int i=0;i<V();i++){
			if(isCyclicUtil(i,visited,recStack)) return true;
		}
		return false;
	}
private:
	bool isCyclicUtil(int v, vector<bool> visited, vector<bool> & recStack){
		visited[v]=true;
		recStack[v]=true;
		for(auto i = adjList[v].begin() ; i!=adjList[v].end() ; i++){
			if(!visited[*i] && isCyclicUtil(*i,visited,recStack)) return true;
			else if (recStack[*i]) return true;
		}
		recStack[v]=false;
		return false;
	}
};

int main() {
	Graph g;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	// g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<g.isCyclic();
	return 0;
}