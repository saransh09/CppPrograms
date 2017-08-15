#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define V 9

class Node {
	int to, weight;
};

vector<Node> edges[V];

void zeroOneBFS(int src) {
	int dist[V];
	for (int i = 0; i < V ; i++) {
		dist[i] = INT_MAX;
	}
	// Double ended queue ie. dequeue to perform a 0/1 BFS
	deque<int> Q;
	dist[src] = 0;
	Q.push_back(src);
	while(!Q.empty()) {
		int v = Q.front();
		Q.pop_front();
		for ( int i = 0 ; i < edges[v].size() ; i++) {
			if (dist[edges[v][i].to] > dist[edges[v][i].weight]) {
				dist[edges[v][i].to] = dist[v] + edges[v][i].weight;
			}
		}
	}
}

int main() {

	return 0;
}