#include <bits/stdc++.h>
using namespace std;
#define p 1000000007

class Solution{
private:
	int rec(vector<vector<int> > & dp, int id, int sum){
		if(sum < 0) return 0;
	    if(id == 0 && sum == 0) return 1;
	    if(id == 0) return 0;

	    if(dp[id][sum] != -1) return dp[id][sum];

	    int ans = 0;
	    for(int i = 0; i < 10; i++) {
	        ans += rec(dp,id - 1, sum - i);
	        ans %= 1000000007;
	    }
	    return dp[id][sum] = ans;
	}
public:
	int solve(int n, int sum){
		int ans = 0;
		vector<vector<int> > dp(n+1,vector<int>(sum+1,-1));
		for(int i=0;i<10;i++){
			ans += rec(dp,n-1,sum-i);
			ans %= p;
		}
		return ans;
	}
};

int main() {
	Solution s;
	cout<<s.solve(2,2);
	return 0;
}