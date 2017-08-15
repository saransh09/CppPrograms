#include <bits/stdc++.h>
using namespace std;

int n,m;

void floodFillHelper(vector<vector<int> > & grid, int x, int y, int prevC, int newC){
	if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) return;
	if(grid[x][y]!=prevC) return;
	grid[x][y] = newC;
	int X[4] = {1,-1,0,0};
	int Y[4] = {0,0,1,-1};
	for(int i = 0 ; i < 4 ; i++){
		floodFillHelper(grid,x+X[i],y+Y[i],prevC,newC);
	}
}

void floodFill(vector<vector<int> > & grid, int x, int y, int newC){
	int prevC = grid[x][y];
	floodFillHelper(grid,x,y,prevC,newC);
}

int main() {
	// int n,m;
	// cin>>n>>m;
	vector<vector<int> > grid = {{1, 1, 1, 1, 1, 1, 1, 1},
			                     {1, 1, 1, 1, 1, 1, 0, 0},
			                     {1, 0, 0, 1, 1, 0, 1, 1},
			                     {1, 2, 2, 2, 2, 0, 1, 0},
			                     {1, 1, 1, 2, 2, 0, 1, 0},
			                     {1, 1, 1, 2, 2, 2, 2, 0},
			                     {1, 1, 1, 1, 1, 2, 1, 1},
			                     {1, 1, 1, 1, 1, 2, 2, 1}};
	floodFill(grid,3,1,3);
	for(int i = 0 ; i < grid.size() ; i++){
		for(int j = 0 ; j < grid[0].size() ; j++) {
			cout<<grid[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}