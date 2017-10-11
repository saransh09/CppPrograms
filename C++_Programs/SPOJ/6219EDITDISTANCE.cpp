#include <bits/stdc++.h>
using namespace std;

int editDistance(string a, string b){
	int m = a.length(), n = b.length();
	int dp[m+1][n+1];
	dp[0][0] = 0;
	for(int i = 0 ; i <= m ; i++){
		for(int j = 0 ; j <= n ; j++){
			if(i==0) dp[i][j] = j;
			else if (j==1) dp[i][j] = i;
			else if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] =  1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	return dp[m][n];
}

int main() {
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		cout<<editDistance(a,b)<<endl;
	}
	return 0;
}