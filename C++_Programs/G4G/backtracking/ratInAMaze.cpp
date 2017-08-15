#include <bits/stdc++.h>
using namespace std;
#define N 4;

bool isSafe(vector<vector<int> > & maze, int x, int y){
	if(x>=0 && x<maze.size() && y>=0 && y<maze[0].size() && maze[x][y]!=0) return true;
	return false;
}

bool solveMazeHelper(vector<vector<int> > & maze, int x, int y, vector<vector<int> > & sol){
	if(x==maze.size()-1 && y==maze[0].size()-1){
		sol[x][y]=1;
		return true;
	}
	if(isSafe(maze,x,y)){
		sol[x][y]=1;
		if(solveMazeHelper(maze,x+1,y,sol)) return true;
		if(solveMazeHelper(maze,x,y+1,sol)) return true;
		sol[x][y]=0;
		return false;
	}
	return false;
}

bool solveMaze(vector<vector<int> > & maze, int x, int y, vector<vector<int> > & sol){
	return solveMazeHelper(maze, 0, 0, sol);
}

int main(){
	vector<vector<int> > maze = {{1,0,0,0},
								 {1,1,0,1},
								 {0,1,0,0},
								 {1,1,1,1}};
	vector<vector<int> > sol(maze.size(),vector<int>(maze[0].size(),0));
	if(solveMazeHelper(maze,0,0,sol)==false) return 0;
	else{
		solveMazeHelper(maze,0,0,sol);
	} 
	for(int i=0;i<sol.size();i++){
		for(int j=0;j<sol[0].size();j++){
			cout<<sol[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}