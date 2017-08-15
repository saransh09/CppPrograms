#include <bits/stdc++.h>
using namespace std;

class Solution{
	int knapsackDP(int W, vector<int> val, vector<int> wt){
		int n = val.size();
		int dp[n+1][W+1];
		for(int i = 0 ; i <= n ; i++){
			for(int w = 0 ; w <= W ; w++){
				if(i==0 || w==0) dp[i][w] = 0;
				else if(wt[i-1]>W) dp[i][w] = dp[-1][w];
				else dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]] + val[i-1]);
			}
		}
		return dp[n][W];
	}
public:
	int knapsack(int W, vector<int> val, vector<int> wt){
		return knapsackDP(W,val,wt);
	}
};

int main() {
	vector<int> val = {60, 100, 120};
	vector<int> wt = {10, 20, 30};
	int W = 50;
	Solution s;
	cout<<s.knapsack(W,val,wt)<<endl;
	return 0;
}