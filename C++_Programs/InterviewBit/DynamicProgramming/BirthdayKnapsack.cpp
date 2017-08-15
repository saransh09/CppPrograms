#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int solve(const vector<int> & A, const vector<int> & B, const vector<int> & C) {
		int n = C.size();
		int m = -1;
		for(int i = 0 ; i < (int)A.size() ; i++){
			m = max(m,A[i]);	
		} 
		vector<vector<int> > dp(m+1,vector<int>(n+1,0));
		for(int i=0 ; i <= m ; i++){
			for(int j=0; j<=n ; j++){
				if (i==0) dp[i][j]=0;
				else if (j==0) dp[i][j]=INT_MAX;
				else{
					if(i>=B[j-1]){
						dp[i][j] = min(dp[i][j-1], dp[i-B[j-1]][j] + C[j-1]);
					}
					else dp[i][j] = dp[i][j-1];
				}
			}
		}
		int ans=0;
		for(int i=0;i<(int)A.size();i++) ans += dp[A[i]][n];
		return ans;
	}
};

int main() {
	vector<int> A = {4,6};
	vector<int> B = {1,3};
	vector<int> C = {5,3};
	Solution s;
	cout<<"The solution is : "<<s.solve(A,B,C);
	return 0;
}