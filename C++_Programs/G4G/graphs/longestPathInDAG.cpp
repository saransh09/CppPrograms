#include <bits/stdc++.h>
using namespace std;

class AdjListNode{
	int v;
	int weight;
public:
	AdjListNode(int _v, int _w) : v(_v), weight(_w) {}
	int getV() { return v; }
	int getWeight() { return weight; }
};

class Graph{
	int V;
	list<AdjListNode> *adj;
public:
	Graph(int V) {
		this -> V = V;
		adj = new list<AdjListNode>[V];
	}
	void addEdge(int u, int v, int weight) {
		AdjListNode node(v, weight);
		adj[u].push_back(node);
	}
	void topologicalSortHelper(int v, bool visited[]. stack<int> & S) {
		visited[v] = true;
		
	}
};

int main() {

	return 0;
}