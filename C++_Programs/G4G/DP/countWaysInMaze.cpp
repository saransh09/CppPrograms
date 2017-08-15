#include <bits/stdc++.h>
using namespace std;

class Solution{
	int countPathsHelper(vector<vector<int> > maze, int R, int C){
		if(maze[0][0]==-1) return 0;
		for(int i = 0 ; i < R ; i++){
			if(maze[i][0]==0) maze[i][0] = 1;
			else break;
		}
		for(int i = 1 ; i < C ; i++){
			if(maze[0][i]==0) maze[0][i] = 1;
			else break;
		}
		for(int i = 1 ; i < R ; i++){
			for(int j = 1 ; j < )
		}
	}
public:
	int countPaths(vector<vector<int> > maze){
		return countPathsHelper(maze,maze.size(),maze[0].size());
	}
};

int main() {

	return 0;
}