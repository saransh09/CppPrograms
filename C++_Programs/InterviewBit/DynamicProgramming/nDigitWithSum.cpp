#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int> > & dp, int id, int sum){
	if(sum<0) return 0;
	if(id==0 && sum==1) return 1;
	else if(id==0) return 0;
	if(dp[id][sum]!=-1) return dp[id][sum];
	int ans = 0;
	for(int i=0;i<10;i++){
		ans += helper(dp,id-1,sum-i);
		ans &= 1000000007;
	}
	return dp[id][sum]=ans;
}

int solve(int a,int b){
	vector<vector<int> > dp(a+1,vector<int>(b+1,-1));
	int ans=0;
	for(int i=0;i<10;i++){
		ans += helper(dp,a-1,b-i);
		ans %= 1000000007;
	}
	return ans;
}

int main() {

	return 0;
}