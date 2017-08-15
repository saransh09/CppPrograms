#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <list>
using namespace std;
class Graph {
	vector<list<int> > adjList;
	int time;
public:
	Graph() {}
	int V() const {
		return adjList.size();
	}
	void addEdge(int src, int dest) {
		int max = src > dest ? src : dest ;
		if (max > V() + 1) {
			adjList.resize(max + 1);
		}
		list<int>::iterator it = find(adjList[src].begin(),adjList[src].end(),dest);
		if (it != adjList[src].end()) {
			throw "You are insterting the edge again";
		}
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	void BFS(int s) {
		vector<char> color(V(),'w');
		vector<int> d(V(),0);
		vector<int> parent(V(),-1);
		color[s] = 'g';
		d[s] = 0;
		parent[s] =  -1;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			cout<<curr<<' ';
			list<int>::iterator it = adjList[curr].begin();
			while(it != adjList[curr].end()) {
				if(color[*it]=='w') {
					color[*it] = 'g';
					parent[*it] = curr;
					d[*it] = d[curr] + 1;
					Q.push(*it);
				}
				color[curr] = 'b';
				it++;
			}
		}
	}
	void DFS() {
		vector<char> color(V(),'w');
		vector<int> pi(V(),-1);
		vector<int> d(V(),0);
		vector<int> f(V(),0);
		time = 0;
		for(int i = 1; i < V() ; i++) {
			if (color[i]=='w') {
				DFSvisit(i,d,f,pi,color);
			}
		}
		cout<<endl<<"The d time stamps are : ";
		for (int i=1;i<V();i++) {
			cout<<d[i]<<' ';
		}
		cout<<endl<<"The f time stamps are : ";
		for (int i=1;i<V();i++) {
			cout<<f[i]<<' ';
		}
	}
private:
	void DFSvisit(int i, vector<int> & d, vector<int> & f, vector<int> & pi, vector<char> & color) {
		color[i] = 'g';
		time += 1;
		d[i] = time;
		cout<<i<<' ';
		list<int>::iterator it = adjList[i].begin();
		while(it != adjList[i].end()) {
			if (color[*it]=='w') {
				pi[*it] = i;
				DFSvisit(*it,d,f,pi,color);
			}
			it++;
		}
		color[i] = 'b';
		time += 1;
		f[i] = time;
	}
public:
};

bool isBipartite(int G[][4], int src) {
	vector<int> color(4,-1);
	color[src] = 1;
	queue<int> Q;
	Q.push(src);
	while(!Q.empty()) {
		int u = Q.front();
		Q.pop();
		for (int v=0; v<4;v++) {
			// color[v] = 1 - 
			if (G[u][v] && color[u]==-1) {
				color[v] = 1 - color[u];
				Q.push(v);
			}
			else if (G[u][v] && color[v]==color[u]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	// Graph G;
	// G.addEdge(1,2);
	// G.addEdge(1,7);
	// G.addEdge(2,3);
	// G.addEdge(2,5);
	// G.addEdge(3,4);
	// G.addEdge(3,7);
	// G.addEdge(4,5);
	// G.addEdge(4,7);
	// G.addEdge(5,6);
	// G.addEdge(6,7);
	// G.DFS();
	int G[][4] = {{0,1,0,1},
				  {1,0,1,0},
				  {0,1,0,1},
				  {1,0,1,0}};
	isBipartite(G,0) ? cout<<"Yes" : cout<<"No";
	return 0;
}