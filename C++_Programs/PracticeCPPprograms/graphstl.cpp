#include <list>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
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
		if ( max + 1 > V() ) {
			adjList.resize(max + 1) ;
		}
		list<int>::iterator it = find(adjList[src].begin(), adjList[src].end(), dest);
		if (it != adjList[src].end()) {
			throw "You are inserting this edge again";
		}
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}

};

int main() {



	return 0;
}