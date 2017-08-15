#include <bits/stdc++.h>
using namespace std;

class Graph{
	vector<vector<int> > adjList;
public:
	int V() {
		return adjList.size();
	}
	void addEdge(int src, int dest){
		int m = src > dest ? src : dest;
		if (V() < m) adjList.resize(m+1);
		if(find(adjList[src].begin(),adjList[dest].end(),dest)!=adjList[src].end()) throw "The edge already exists";
		adjList[src].push_back(dest);	
	}
	void floyWarshall(){
		vector<vector<int> > dist = adjList;
		for(int k = 0 ; k < V() ; k++){
			for(int i = 0 ; i < V() ; i++){
				for(int j = 0 ; j < V() ; j++) {
					if (dist[i][k]+dist[j][k] < dist[i][j]) dist[i][j] = dist[i][k]+dist[j][k];  
				}
			}
		}
		for(int i = 0 ; i < (int)dist.size() ; i++){
			for(int j = 0 ; j < (int) dist[i].size() ; j++) {
				cout<<dist[i][j]<<' ';
			}
			cout<<endl;
		}
	}
};

int main(){

	return 0;
}