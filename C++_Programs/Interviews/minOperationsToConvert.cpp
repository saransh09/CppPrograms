#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) {
	return min(x,min(y,z));
}

int editDist(string s1, string s2, int m, int n){
	if(m==0) return n;
	if(n==0) return m;
	if(s1[m-1]==s2[n-1]) return editDist(s1,s2,m-1,n-1);
	return min(editDist(s1,s2,m-1,n),editDist(s1,s2,m,n-1),editDist(s1,s2,m-1,n-1))+1;
}

int editDistDP(string s1, string s2, int m, int n){
	int dp[m+1][n+1];
	for(int i = 0 ; i <= m ; i++) {
		for(int j = 0 ; j <= n ; j++) {
			if(i==0) dp[i][j] = j;
			else if(j==0) dp[i][j] = i;
			else if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = 1 + min(dp[i-1][j],dp[i-1][j-1],dp[i][j-1]);
		}
	}
	return dp[m][n];
}

int main() {
	string s1 = "sunwkjeiofjwaorigjoiqwrjgoiwqdaywkjfrhnweiorioerjoiwerjwioerw4u3498tsdkfmejfewfpjopwewkefm";
	string s2 = "saturdayelfjweirfhweoirjioewqrjwioslkfejweiofjweiorjoeirjiowerjwoierjoiwewekfnwkefwfpowefer";
	cout<<editDistDP(s1,s2,s1.size(),s2.size())<<endl;
	return 0;
}