#include <bits/stdc++.h>
using namespace std;

int min(int a, int b, int c){
	int m = a;
	if (m > b) 
		m = b;
	if (m > c) 
		m = c;
	return m;
}

void printMaxSubArray(vector<vector<int> > & grid){
	int m = grid.size(), n = grid[0].size();
	int temp[m+1][n+1];
	int max_of_s, max_i, max_j;
	for(int i = 0 ; i < m ; i++) temp[i][0] = grid[i][0];
	for(int j = 0 ; j < n ; j++) temp[0][j] = grid[0][j];
	for(int i = 1 ; i < m ; i++){
		for(int j = 1 ; j < n ; j++) {
			if (grid[i][j]==1) temp[i][j] = min(temp[i-1][j-1],temp[i-1][j],temp[i][j-1]) + 1;
			else temp[i][j]=0;
		}
	}
	max_of_s = temp[0][0]; max_i = 0; max_j = 0;
  	for(int i = 0; i < m; i++){
    	for(int j = 0; j < n; j++){
      		if(max_of_s < temp[i][j]){
         		max_of_s = temp[i][j];
         		max_i = i; 
         		max_j = j;
      		}        
    	}                 
  	}
  	for(int i = max_i ; i < max_i + max_of_s ; i++) {
  		for(int j = max_j ; j < max_j + max_of_s ; j++) {
  			cout<<temp[i][j]<<' ';
  		}
  		cout<<endl;
  	}
}

int main() {
	vector<vector<int> > grid = {{0, 1, 1, 0, 1}, 
                   				 {1, 1, 0, 1, 0}, 
                   				 {0, 1, 1, 1, 0},
                   				 {1, 1, 1, 1, 0},
                    			 {1, 1, 1, 1, 1},
                   				 {0, 0, 0, 0, 0}};
    printMaxSubArray(grid);
	return 0;
}