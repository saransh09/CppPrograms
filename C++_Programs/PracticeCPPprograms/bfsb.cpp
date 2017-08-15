#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
public:
	
	Graph(int V) : V(V) {
		adj = new list<int>[V];
	}

	void addEdge(int src, int dest) {
		adj[src].push_back(dest);
	}

	void BFS(int s) {
		bool *visited = new bool[V];
		for (int i=0; i<V; i++) {
			visited[i] = false;
		}
		list<int> queue;
		visited[s] = true;
		queue.push_back(s);
		list<int>::iterator it;
		while(!queue.empty()) {
			s = queue.front();
			cout<<s<<' ';
			queue.pop_front();
			for (it = adj[s].begin() ; it != adj[s].end() ; it++) {
				if(!visited[*it]) {
					visited[*it] = true;
					queue.push_back(*it);
				}
			}
		}
	}

};

int main() {
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3); 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}