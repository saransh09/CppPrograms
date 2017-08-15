#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int> > islands, int r, int c,int R, int C, vector<vector<bool> > visited) {
	return (row>=0 && (r<R) && (c>=0) && (c<C) && islands[r][c] && !visited[r][c]);
}

void DFS(vector<vector<int> > & islands, vector<vector<bool> > visited, int r, int c){

}

int countIslands(vector<vector<int> > islands) {
	vector<vector<bool> > visited(islands.size(),vector<bool>(islands[0].size(),false));

}

int main() {
	vector<vector<int> > v =  {{1, 1, 0, 0, 0},
							   {0, 1, 0, 0, 1},
							   {1, 0, 0, 1, 1},
							   {0, 0, 0, 0, 0},
							   {1, 0, 1, 0, 1}};
    
	return 0;
}