#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

class Graph {
	vector<list<int> > adjList;
public:
	Graph() {}
	int V() const { return adjList.size(); }
	void addEdge(int src, int dest) {
		int max = src > dest ? src : dest ;
		if (max > V() + 1) {
			adjList.resize(max + 1);
		}
		list<int>::iterator it = find(adjList[src].begin(),adjList[src].end(),dest);
		if (it != adjList[src].end()) {
			throw "You are adding the edge again";
		}
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	// void BFS() {
	// 	vector<bool> visited(V(), false);
	// 	for (int i = 1; i < visited.size() ; i++) {
	// 		if ( visited[i] == true) {
	// 			continue;
	// 		}
	// 		queue<int> Q;
	// 		Q.push(i);
	// 		visited[i] = true;
	// 		while (!Q.empty()) {
	// 			int curr = Q.front();
	// 			Q.pop();
	// 			cout << curr << ' ';
	// 			list<int>::iterator it = adjList[curr].begin();
	// 			while(it != adjList[curr].end()) {
	// 				if (visited[*it]==false) {
	// 					Q.push(*it);
	// 					visited[*it] = true;
	// 				}
	// 				it++;
	// 			}
	// 		}
	// 	}
	// }
	void BFS(int s) {
		vector<char> color(V(), 'w');
		vector<int> d(V(),INT_MAX);
		vector<int> parent(V(),INT_MIN);
		color[s] = 'g';
		d[s] = 0;
		parent[s] = INT_MIN;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty()) {
			int curr = Q.front();
			Q.pop();
			cout<<curr<<' ';
			list<int>::iterator it = adjList[curr].begin();
			while(it != adjList[curr].end()) {
				if (color[*it] == 'w') {
					color[*it] = 'g';
					d[*it] = d[curr] + 1 ;
					parent[*it] = curr;
					Q.push(*it);
				}
				it++;
			}
			color[curr] = 'b';
		}
	}
};


int main() {
	Graph G;
	G.addEdge(1,2);
	G.addEdge(1,5);
	G.addEdge(2,3);
	G.addEdge(2,4);
	G.addEdge(2,5);
	G.addEdge(3,4);
	G.addEdge(4,5);
	G.BFS(2);
}