#include <bits/stdc++.h>
using namespace std;

long long calcCounts(string s){
	int n = s.length();
	long long dp[n+1];
	if(s[0]=='0') return (long long)0;
	dp[0] = dp[1] = 1;
	for(int i = 2 ; i <= n ; i++){
		dp[i] = 0;
		char c1 = s[i-2] - '0' , c2 = s[i-1] - '0';
		if(c1==1 || (c1==2 && c2<=6)) dp[i] += dp[i-2];
		if(c2!=0) dp[i] += dp[i-1];
	}
	return dp[n];
}

int main() {
	while(1){
		string s;
		cin>>s;
		if(s=="0") break;
		cout<<calcCounts(s)<<endl;
	}
	return 0;
}