#include <bits/stdc++.h>
using namespace std;

class Solution{
	void isSubsetSumHelper(vector<int> A, int index, int sum, bool & a){
		if(sum<0 || index>A.size()) return;
		if(sum==0){ 
			a |= 1;
			return;
		}
		isSubsetSumHelper(A,index+1,sum-A[index],a);
		isSubsetSumHelper(A,index+1,sum,a);
		return;
	}
	bool isSubsetSumHelperDP(vector<int> A, int sum){
		int n = A.size();
		bool dp[n+1][sum+1];
		for(int i = 0 ; i <= n ; i++) dp[i][0] = true;
		for(int j = 0 ; j <= sum ; j++) dp[0][j] = false;
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= sum ; j++){
				if(j<A[i-1]) dp[i][j] = dp[i-1][j];
				else if(j >= A[i-1]) dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
			}
		}
		return dp[n][sum];
	}
public:
	bool isSubsetSum(vector<int> A, int sum){
		bool a = false;
		// isSubsetSumHelper(A,0,sum,a);
		return isSubsetSumHelperDP(A,sum);
		// return a;
	}
};

int main() {
	vector<int> A = {1,2,3,5,2,4,2,6,7,3,5,7,4,2,1,4,5,6,7,8,9,7,5,4,3,2,4,5,6,7,7,6,4,3,3,5,7,8,25,2,5,34,2,74,346};
	Solution s;
	cout<<s.isSubsetSum(A,79)<<endl;
	return 0;
}