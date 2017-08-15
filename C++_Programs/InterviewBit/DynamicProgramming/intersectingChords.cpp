#include <bits/stdc++.h>
using namespace std;
#define p 1000000007

class Solution{
private:
	int checkChords(int n, vector<long long int> & dp){
		if (n<=0) return 1;
		else if(dp[n]!=0) return dp[n];
		else {
			for(int i=1;i<=n;i++){
				dp[n]+=((checkChords(n-i,dp)%p)*(checkChords(i-1,dp)%p));
				dp[n]=dp[n]%p;
			}
			return dp[n]%p;
		}
	}
public:
	int chordCount(int n){
		vector<long long int> dp(n+1,0);
		dp[0]=0 ; dp[1]=1 ; dp[2]=2;
		dp[n] = checkChords(n,dp)%p;
		return dp[n];
	}
};

int main() {
	Solution s;
	cout<<s.chordCount(100);
	return 0;
}