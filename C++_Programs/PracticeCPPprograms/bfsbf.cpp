#include <bits/stdc++.h>
using namespace std;

class Graph {
	vector<list<int> > adjList;
public:
	
	Graph()  {}

	int V() const {
		return adjList.size();
	}

	int addEdge(int src, int dest) {
		int max = src > dest ? src : dest;
		if (max > V() + 1) {
			adjList.resize(max+1);
		}
		list<int>::iterator it = find(adjList[src].begin(), adjList[src].end(), dest);
		if (it != adjList[src].end()) {
			throw "The edge already exists";
		}
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}

	void deleteEdge(int src, int dest) {
		list<int>::iterator it = adjList[src].begin();
		while(it!=adjList[src].end()) {
			if(*it == dest) {
				break;
			}
			it++;
		}
		if (it == adjList[src].end()) {
			throw "The edge does not exist";
		}
		else{
			adjList[src].erase(it);
			list<int>::iterator i = adjList[dest].begin();
			while(i!=adjList[dest].end()) {
				if(*i == src) {
					break;
				}
				i++;
			}
			adjList[dest].erase(i);
		}
	}

	void BFS(int s) {
		vector<char> color(V(),'w');
		vector<int> parent(V(),-1);
		vector<int> d(V(),0);
		color[s] = 'g';
		parent[s] = -1;
		d[s] = 0;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			cout<<curr<<' ';
			list<int>::iterator it = adjList[curr].begin();
			while(it != adjList[curr].end()) {
				if(color[*it] == 'w') {
					color[*it] = 'g';
					d[*it] = d[curr] + 1;
					parent[*it] = curr;
					Q.push(*it);
				}
				color[curr] = 'b';
				it++;
			}
		}
	}

	void DFS() {
		vector<bool> visited(V(),false);
		for (int i=0;i<V(); i++) {
			if(visited[i]==false) {	
				DFSUtil(i, visited);
			}
		}
	}

	void DFSUtil(int v, vector<bool> & visited) {
		visited[v] = true;
		cout << v << ' ';
		list<int>::iterator it = adjList[v].begin();
		while(it != adjList[v].end()) {
			if (visited[*it] != true) {
				DFSUtil(*it, visited);
			}
			it++;
		}
	} 
};

int main() {

	return 0;
}