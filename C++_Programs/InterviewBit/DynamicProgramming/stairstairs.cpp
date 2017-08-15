#include <bits/stdc++.h>
using namespace std;

long stairs(int n){
	vector<long> dp(n+1,0);
	dp[0]=0, dp[1]=1, dp[2]=2;
	if(n<3) return dp[n];
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int main() {
	cout<<stairs(100)<<endl;
	return 0;
}