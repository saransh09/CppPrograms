#include <iostream>
#include <queue>
#include <list>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Graph {
	vector<list<int> > adjList;
public:
	Graph() {}
	int V()  const {
		return adjList.size();
	}
	void addEdge(int src, int dest) {
		int max = src > dest ? src : dest ;
		if ( max > 1 + V() ) {
			adjList.resize(max+1);
		}
		list<int>::iterator it = find(adjList[src].begin(),adjList[src].end(), dest);
		if ( it != adjList[src].end()) {
			throw "You are inserting the edge again";
		}
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	void BFS() {
		vector<bool> visited(V(), false);
		for ( int i = 0; i < visited.size() ; i++) {
			if (visited[i]==true) {
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
					if (visited[*it] == false) {
						Q.push(*it);
						visited[*it] = true;
					}
					it++;
				}
			}
		}
	}

};