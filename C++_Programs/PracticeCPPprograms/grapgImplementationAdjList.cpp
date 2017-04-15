#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<typename T>
class AdjListNode {
	T dest;
	AdjListNode * next;
public:
	AdjListNode() : next(0) {}
	AdjListNode(T d) : dest(d), next(0) {}
	template<typename U>
	friend class AdjList;
};
template<typename T>
class AdjList {
	AdjListNode<T> * head;
public:
	// AdjListNode() : head(0) {}
	AdjListNode<T> * newAdjList(T dest) {
		AdjList *newnode = new AdjList(dest);
		return newnode;
	}	
	template<typename U>
	friend class Graph;
};
template<typename T>
class Graph {
	int V;
	AdjList<T> *array;
public:
	Graph(int V) : V(V), array(0) {}
	Graph * createGraph(int V) {
		Graph * graph = new Graph(V);
		graph -> array = new AdjList * () 
	}
};



int main() {



	return 0;
}