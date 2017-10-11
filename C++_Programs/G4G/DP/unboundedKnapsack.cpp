#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsackRec(int W, int n, int val[], int wt[]){
	int dp[W+1];
	memset(dp,0,sizeof(dp));
	for(int i = 0 ; i <= W ; i++){
		for(int j = 0 ; j <= n ; j++){
			if(wt[j] <= i){
				dp[i] = max(dp[i],dp[i-wt[j]]+val[j]);
			}
		}
	}
	return dp[W];
}

int knapsack(int W, int n, int val[], int wt[]){
	int dp[n+1][W+1];
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= W ; j++){
			if(i==0 || j==0) dp[i][j] = 0;
			else if(wt[i-1]<=j) dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
			else dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][W];
}

int main() {
	int W = 100;
	int val[] = {10,30,20};
	int wt[] = {5,10,15};
	int n = sizeof(val)/sizeof(val[0]);
	cout<<unboundedKnapsackRec(W,n,val,wt);
	return 0;
}