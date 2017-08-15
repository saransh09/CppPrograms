#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int minCost(vector<int> cost, int W){
		vector<int> val, wt;
		for(int i = 0 ; i < (int)cost.size() ; i++){
			if(cost[i]!=-1) {
				val.push_back(cost[i]);
				wt.push_back(i+1);
			}
		}
		int n = val.size();
		int dp[n+1][W+1];
		memset(dp,0,sizeof(dp));
		for(int i = 0 ; i <= W ; i++) dp[0][i] = INT_MAX;
		for(int i = 1 ; i <= n ; i++) dp[i][0] = 0;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= W ; j++){
				if(wt[i-1]>j){
					dp[i][j] = dp[i-1][j];
				}
				else{
					dp[i][j] = min(dp[i-1][j],dp[i][j-wt[i-1]]+val[i-1]);
				}
			}
		}
		return ((dp[n][W] == INT_MAX) ? -1 : dp[n][W]);	
	}
};

int main() {
	vector<int> cost = {1,2,4,5,6,8,9,10,12,13,14};
	Solution s;
	cout<<s.minCost(cost,32)<<endl;	
	return 0;
}