#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Graph {
	vector<list<int> > adjList;
public:
	int V() const {
		return adjList.size();
	}
	void addEdge(int src, int dest) {
		int max = src > dest ? src : dest;
		if ( max + 1 > V() ) {
			adjList.resize(max + 1);
		}
		list<int>::iterator it = find(adjList[src].begin(), adjList[dest].end(), dest);
		if (it != adjList[src].end()) {
			throw "You are inserting this edge again";
		}
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	void BFS() {
		vector<bool> visited(V(), false);
		for (int i = 0; i < visited.size(); i++) {
			if (visited[i] == true) {
				continue;
			}
			queue<int> Q;
			Q.push(i);
			visited[i] = true;
			while(!Q.empty()) {
				int current = Q.front();
				Q.pop();
				cout << current << ' ';
				list<int>::iterator it = adjList[current].begin();
				while (it != adjList[current].end()) {
					if (visited[*it] == true) {
						Q.push(*it);
						visited[*it] = true;
					}
					it ++;
				}
			}
		}
	}
	void DFS() {
		vector<bool> visited(V(),false);
		for ( int i = 0; i < visited.size() ; i++) {
			if ( visited[i] == true) {
				continue;
			}
			DFSUtil(i, visited);
		}
	}
	void DFSUtil(int src, vector<bool> & visited) {
		visited[src] = true;
		cout<<src<<' ';
		list<int>::iterator it = adjList[src].begin();
		while (it != adjList[src].end()) {
			if (visited[*it] == false) {
				DFSUtil(*it, visited);
			}
			it++;
		}
	}
};

int main() {
	Graph G;
	G.addEdge(1,2);
	G.addEdge(1,5);
	// G.addEdge(5,1);
	return 0;
}