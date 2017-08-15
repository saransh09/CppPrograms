#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

	int knapsackRec(int W, vector<int> wt, vector<int> val, int n){
		if(n==0 || W==0) return 0;
		if (wt[n-1]>W) return knapsackRec(W,wt,val,n-1);
		else return max(val[n-1] + knapsackRec(W-wt[n-1],wt,val,n-1), knapsackRec(W,wt,val,n-1));
	}
	int knapsackDP(int W, vector<int> wt, vector<int> val, int n){
		vector<vector<int> > dp(n+1,vector<int>(W+1));
		for(int i=0;i<=n;i++){
			for(int w=0;w<=W;w++){
				if(i==0 || w==0) dp[i][w]=0;
				else if(wt[i-1]<=w) dp[i][w] = max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
				else return dp[i][w] = dp[i-1][w];
			}
		}
		return dp[n][W];
	}
};

int main() {
	
	return 0;
}