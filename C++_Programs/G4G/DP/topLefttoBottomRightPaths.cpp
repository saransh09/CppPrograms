#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
	long long numberOfPathsRec(int m, int n){
		if(m==1 || n==1) return 1;
		return numberOfPathsRec(m-1,n) + numberOfPathsRec(m,n-1);
	}
	long long numberOfPathsDP(int m, int n){
		long long
		dp[m][n];
		for(int i = 0 ; i < m ; i++) dp[i][0] = 1;
		for(int j = 0 ; j < n ; j++) dp[0][j] = 1;
		for(int i = 1 ; i < m ; i++){
			for(int j = 1 ; j < n ; j++){
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m][n];
	}
public:
	long long numberOfPaths(int m, int n){
		return numberOfPathsDP(m,n);
	}
};

int main() {
	int m,n;
	cin>>m>>n;
	Solution s;
	cout<<s.numberOfPaths(m,n)<<endl;
	return 0;
}