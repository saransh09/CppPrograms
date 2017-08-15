#include <iostream>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Graph {
	vector<list<int> > adjList;
public:
	Graph() {}
	int V() const {
		return adjList.size();
	}
	void addEdge(int src, int dest) {
		int max = src > dest ? src : dest ;
		if (max > V() + 1) {
			adjList.resize(max+1);
		}
		list<int>::iterator it = find(adjList[src].begin(),adjList[src].end(),dest);
		if (it != adjList[src].end()) {
			throw "You are inserting the edge again";
		}
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	void BFS(int s) {
		vector<char> color(V(),'w');
		vector<int> d(V(),INT_MAX);
		vector<int> parent(V(),0);
		color[s] = 'g';
		d[s] = 0;
		parent[s] = -1;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			cout<<curr<<' ';
			list<int>::iterator it = adjList[curr].begin();
			while(it != adjList[curr].end()) {
				if (color[*it]=='w') {
					color[*it] = 'g';
					d[*it] = d[curr] + 1;
					parent[*it] = curr;
					Q.push(*it);
				}
				it++;
			}			
		}
	}
	void DFS() {
		vector<bool> visited(V(),false);
		for (int i=1;i<V();i++) {
			if (visited[i] == false) {
				DFSUtil(i,visited);
			}
		}
	}
private:
	void DFSUtil(int v, vector<bool> & visited) {
		visited[v] = true;
		cout<<v<<' ';
		list<int>::iterator it = adjList[v].begin();
		while (it != adjList[v].end()) {
			if (visited[*it] != true) {
				DFSUtil(*it, visited);
			}
			it++;
		}
	}
};



int main() {
	Graph G;
	G.addEdge(1,2);
	G.addEdge(1,7);
	G.addEdge(2,3);
	G.addEdge(2,5);
	G.addEdge(3,4);
	G.addEdge(3,7);
	G.addEdge(4,5);
	G.addEdge(4,7);
	G.addEdge(5,6);
	G.addEdge(6,7);
	G.BFS(5);
	cout<<endl<<endl;
	G.DFS();
	return 0;
	return 0;
}