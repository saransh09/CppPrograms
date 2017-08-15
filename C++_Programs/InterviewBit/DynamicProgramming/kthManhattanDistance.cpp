#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
	bool check(int i, int j, int n, int m){
		if(i>=0 && j>=0 && i<n && j<m) return 1;
		return 0;
	}
	vector<vector<int> > solveHelper(int A, vector<vector<int> > & B) {
		int n = B.size();
		int m = B[0].size();
		vector<vector<vector<int> > > dp(2);
		dp[0] = dp[1] = B;
		int rplus[] = {1,0,0,-1};
		int cplus[] = {0,1,-1,0};
		for(int k=0;k<=A;k++){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if (k==0) dp[k][i][j]=B[i][j];
					else{
						int ans = dp[(k-1)%2][i][j];
						for(int p=0;p<4;p++){
							int temp_i = i+rplus[p];
							int temp_j = j+cplus[p];
							if(check(temp_i,temp_j,n,m)) ans = max(ans, dp[(k-1)%2][temp_i][temp_j]);
						}
						dp[k%2][i][j] = ans;
					}
				}
			}
		}
		return dp[A%2];
	}
public:
	vector<vector<int> > solve(int A, vector<vector<int> > & B) {
		return solveHelper(A,B);
	}
};

int main() {

	return 0;
}