#include <bits/stdc++.h>
using namespace std;

int minCostPath(vector<vector<int> > & cost){
	int m = cost.size();
	int n = cost[0].size(); 
	int tc[m+1][n+1];
	tc[0][0] = 0;
	for(int i = 1 ; i < m ; i++) tc[i][0] = tc[i-1][0] + cost[i][0];
	for(int j = 1 ; j < n ; j++) tc[0][j] = tc[0][j-1] + cost[0][j];
	for(int i = 1 ; i < m ; i++){
		for(int j = 1 ; j < n ; j++) {
			tc[i][j] = min(tc[i-1][j-1],min(tc[i-1][j],tc[i][j-1])) + cost[i][j];
		}
	}
	return tc[m][n];
}

int main() {
	vector<vector<int> > cost = {{1,2,3},
   								 {4,8,2},
   								 {1,5,3}};
    cout<<minCostPath(cost);
	return 0;
}