#include <bits/stdc++.h>
using namespace std;

class Solution{
	int minCostHelper(vector<vector<int> > cost, int n, int m){
		if(m<0 || n<0) return INT_MAX;
		else if(m==0 && n==0) return cost[n][m];
		else return cost[n][m] + min(minCostHelper(cost,n-1,m-1),min(minCostHelper(cost,n-1,m),minCostHelper(cost,n,m-1)));
	}
	int minCostHelperDP(vector<vector<int> > cost){
		int n = cost.size()-1;
		int m = cost[0].size()-1;
		int tc[n+1][m+1];
		tc[0][0] = cost[0][0];
		for(int i = 1 ; i <= n ; i++){
			tc[i][0] = cost[i][0] + tc[i-1][0]; 
		}
		for(int j = 1 ; j <= m ; j++){
			tc[0][j] = cost[0][j] + tc[0][j-1];
		}
		for(int i = 1 ; i <= m ; i++){
			for(int j = 1 ; j <= n ; j++){
				tc[i][j] = cost[i][j] + min(tc[i-1][j-1],min(tc[i-1][j],tc[i][j-1]));
			}
		}
		return tc[n][m];
	}
public:
	int minCost(vector<vector<int> > cost){
		int n = cost.size();
		int m = cost[0].size();
		// return minCostHelper(cost,n-1,m-1);
		return minCostHelperDP(cost);
	}
};

int main() {
	vector<vector<int> > cost = {{1, 2, 3},
                      			 {4, 8, 2},
                                 {1, 5, 3}};
    Solution s;
    cout<<s.minCost(cost)<<endl;
	return 0;
}