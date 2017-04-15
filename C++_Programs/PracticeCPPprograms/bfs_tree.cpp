#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <climits>
#include <algorithm>
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
		if(it != adjList[src].end()) {
			throw "Adding the edge again";
		} 
		adjList[src].push_back(dest);
		adjList[dest].push_back(src); 
	}
	void BFS(int s) {
		vector<char> color(V(),'w');
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
				if (color[*it]== 'w') {
					color[*it] = 'g';
					d[*it] = d[curr] + 1;
					parent[*it] = curr;
					Q.push(*it);
				}
				it++;
			}
		}
	}
};

int main() {
	
	return 0;
}