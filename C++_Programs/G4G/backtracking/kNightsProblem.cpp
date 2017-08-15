#include <bits/stdc++.h>
using namespace std;
#define N 8

bool isSafe(int x, int y, int sol[N][N]){
	return (x>=0 && x<N && y>=0 && y<N && sol[x][y]);
}

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N]){
	int k, next_x, next_y;
	if(movei==N*N) return true;
	for(k=0;k<8;k++){
		next_x = x + xMove[k];
		next_y = y + yMove[k];
		if(isSafe(next_x,next_y, sol)){
			sol[next_x][next_y] = movei;
			if(solveKTUtil(next_x,next_y,movei+1,sol,xMove,yMove)){
				return true;
			}
			else {
				sol[next_x][next_y] = -1;
			}
		}
	}
	return true;
}

bool solveKT(vector<vector<int> > & finSol){
	int sol[N][N];
	memset(sol,-1,sizeof(sol));
	int xMove[] = {0,-1,-1,-1,0,1,1,1};
	int yMove[] = {-1,-1,0,1,1,1,0,-1};
	sol[0][0]=0;
	if(solveKTUtil(0,0,0,sol,xMove,yMove)){
		return false;	
	} 
	else{
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				finSol[i].push_back(sol[i][j]);
			}
		}
		return true;
	}
}

int main(){
	vector<vector<int> > sol;
	solveKT(sol);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<sol[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}