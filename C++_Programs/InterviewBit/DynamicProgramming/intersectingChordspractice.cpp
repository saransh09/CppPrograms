#include <bits/stdc++.h>
using namespace std;
#define p 1000000007

class Solution{
public:
	int numberChords(int n){
		vector<long> dp(n+1,0);
		dp[0]=0, dp[1]=1, dp[2]=2;
		dp[n]=helper(n,dp);
		return dp[n]%p;
	}
private:
	long helper(int n, vector<long> dp){
		if(n<=0){
			return 1;
		}
		else if(dp[n]!=0){ 
			return dp[n]%p;
		}
		else{
			for(int i=1; i<n; i++){
				return ((helper(n-i,dp)%p) + (helper(i-1,dp)%p));
			}
		}
		return dp[n]%p;
	}
};

int main() {

	return 0;
}