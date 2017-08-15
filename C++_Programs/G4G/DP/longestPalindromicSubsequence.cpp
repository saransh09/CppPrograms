#include <bits/stdc++.h>
using namespace std;

class Solution{
	int lpsRec(string s, int i, int j){
		if(i==j) return 1;
		if(s[i]==s[j] && i+1==j) return 2;
		if(s[i]==s[j]) return lpsRec(s,i+1,j-1)+2;
		return max(lpsRec(s,i+1,j),lpsRec(s,i,j-1));
	}
	int lpsDP(string s){
		int n = s.length()-1;
		int dp[n][n];
		for(int i = 0 ; i < n ; i++) dp[i][i] = 1;
		for(int c1 = 2 ; c1 <= n ; c1++){
			for(int i = 0 ; i < n - c1 + 1; i++){
				int j = i + c1 - 1;
				if(s[i]==s[j] && c1==2) dp[i][j] = 2;
				else if(s[i]==s[j]) dp[i][j] = dp[i+1][j-1] + 2;
				else dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}
		return dp[0][n-1];
	}
public:
	int lps(string s){
		return lpsDP(s);
	}
};

int main() {
	string str = "GEEKSFORGEEKS";
	Solution s;
	cout<<s.lps(str)<<endl;
	return 0;
}