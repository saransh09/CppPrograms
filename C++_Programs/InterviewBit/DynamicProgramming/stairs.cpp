#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
	int CountStepsHelper(int n, vector<int> & dp){
		if(n<=0) return 0;
		else if (dp[n]!=0) return dp[n];
		else{
			for(int i = 1; i <= n ; i++){
				// int toAdd = CountStepsHelper(n-i,dp) + CountStepsHelper(n-i-1,dp);
				dp[n] += CountStepsHelper(n-i,dp) + CountStepsHelper(n-i-1,dp);
				// cout<<toAdd;
				// dp[n] += toAdd;
			}
			return dp[n];
		}
	}
public:
	int countSteps(int n){
		vector<int> dp(n+1,0);
		dp[0]=0;dp[1]=1;dp[2]=2;
		if(n<3) return dp[n];
		CountStepsHelper(n,dp);
		return dp[n];
	}
};

int main() {
	Solution s;
	cout<<endl<<s.countSteps(100);
	return 0;
}