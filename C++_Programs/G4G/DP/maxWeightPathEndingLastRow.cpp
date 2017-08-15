#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int maxCost(vector<vector<int> > cost){
		int dp[cost.size()][cost[0].size()];
		memset(dp,0,sizeof(dp));
		dp[0][0] = 0;
		for(int i = 1 ; i < cost[0].size() ; i++) dp[i][0] = cost[i][0] + dp[i-1][0];
		for(int i = 1 ; i < cost.size() ; i++){
			for(int j = 1 ; j < cost[0].size() ; j++){
				dp[i][j] = cost[i][j] + max(dp[i-1][j-1],dp[i-1][j]);
			}
		}
		int result = 0;
		for(int i = 0 ; i < cost[0].size() ; i++){
			if(result < dp[cost.size()-1][i]) {
				result = dp[cost.size()-1][i];
			}
		}
		return result;
	}
};

int main() {
	vector<vector<int> > cost  = 
	{{4,1,5,6,1},
     {2,9,2,11,10},
     {15,1,3,15,2},
     {16,92,41,4,3},
     {8,142,6,4,8}};
     Solution s;
     cout<<s.maxCost(cost)<<endl;
	return 0;
}