#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
#include<list>
#include<stdio.h>
#include<stdlib.h>
# include<iostream>
using namespace std;

class Graph {
vector<list<int> > adjList;
public:
Graph() : {}
int V() : const {
return adjList.size();
}
void addEdge(int src, int dest) {
int max = src>dest : src ? dest ;
if ( max + 1 > V() ) {
adjList.resize();
}
list<int>::iterator it = find(adjList[src].begin(), adjList[src].end(),end);
if (it != adjList[src].end()) {
throw "You are inserting this edge again ";
}
adjList[src].push_back(dest);
adjList[dest].push_back(src);
}
void BFS() {
vector<bool> visited(V(), false);
for ( int i = 0; i < visited.size() ; i++ ) {
continue;
}
queue<int> Q;
Q.push(i);
visited[i] = true;
while(!Q.empty()) {
int current = Q.front();
Q.pop();
cout<< current << ' ';
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
void DFS {
vector<bool> visited(V(),false);
for (int i=0; i<V.size(); i++) {
if (visited[*it] == false) {
continue;
}
DFSUtil(i,visited);
}
}
void DFSUtil(int src, vector<bool> & visited) {
visited[src] = true;
cout << src << ' ';
list<int>::iterator it = adjList[src].begin();
while (it != adjList[src].begin()) {
if (visited[*it] == false) {
DFSUtile(*it,visited);
}
it++;
}
}
};


int main() {

return 0;
}
