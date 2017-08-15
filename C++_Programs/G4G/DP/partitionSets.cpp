#include <bits/stdc++.h>
using namespace std;

class Solution{
	int countRec(int n, int k){
		if(n==0 || k==0 || k>n) return 0;
		if(k==1 || k==n) return 1;
		return k*countRec(n-1,k)+countRec(n-1,k-1);  
	}
	int countDP(int n, int k){
		int dp[n+1][k+1];
		for(int i = 0 ; i <= n ; i++){
			dp[i][0] = 0;
		}
		for(int j = 0 ; j <= k ; j++){
			dp[0][j] = 0;
		}
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= k ; j++){
				if(j==1 || i==j) dp[i][j] = 1;
				else dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
			}
		}
		return dp[n][k];
	}
public:
	int count(int n, int k){
		return countDP(n,k);
	}
};

int main() {
	Solution s;
	cout<<s.count(453,37)<<endl;
	// cout<<s.count(3,2)<<endl;
	return 0;
}