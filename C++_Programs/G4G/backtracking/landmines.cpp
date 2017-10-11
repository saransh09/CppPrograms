#include <bits/stdc++.h>
using namespace std;

int mx[] = {1,0,-1,0};
int my[] = {0,1,0,-1};

bool isSafe(int mat[12][10], bool visited[12][10],int x, int y){
	if(mat[x][y]==0 || visited[x][y]) return false;
	else return true;
}

bool isValid(int x, int y){
	if(x<0 || y<0 || x>=12 || y>=10) return false;
	else return true;
}

void markUnsafeCell(int mat[12][10]){
	for(int i = 0 ; i < 12 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			if(mat[i][j]==0){
				for(int k = 0 ; k < 4 ; k++){
					if(isValid(i + mx[k],j + my[k])){
						mat[i + mx[k]][j + my[k]] = -1;
					}
				}
			}
		}
	}
	for(int i = 0 ; i < 12 ; i++){
		for(int j = 0 ; j < 10 ; j++){
			if (mat[i][j]==-1) mat[i][j] = 0;
		}
	}
}

void findShortestPathUtil(int mat[12][10], bool visited[12][10], int i, int j, int & minDist, int dist){
	if(j==9){
		minDist = min(dist,minDist);
		return;
	}
	if(dist > minDist){
		return;
	}
	visited[i][j] = true;
	for(int k = 0 ; k < 4 ; k++){
		if(isValid(i + mx[k],j + my[k]) &&
			isSafe(mat,visited,i + mx[k],j + my[k])){
			findShortestPathUtil(mat,visited,i+mx[k],j+my[k],minDist,dist+1);
		}
	}
	visited[i][j] = false;
}

void findShortestPath(int mat[12][10]){
	int minDist = INT_MAX;
	bool visited[12][10];
	markUnsafeCell(mat);
	for(int i = 0 ; i < 12 ; i++){
		memset(visited,false,sizeof(visited));
		findShortestPathUtil(mat,visited,i,0,minDist,0);
		if(minDist == 9){
			break;
		}
	}
	if(minDist != INT_MAX){
		cout<<"Length of the shortest path is : "<<minDist<<endl;
	}
	else {
		cout<<"Destination is not reachable from the given source"<<endl;
	}
}

int main() {
	int mat[12][10] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }
    };
    findShortestPath(mat);
	return 0;
}