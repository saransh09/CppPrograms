#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int lap(const vector<int> & A){
		int n = A.size();
		if(A<3) return n;
		vector<vector<int> > dp(n,vector<int>(n,-1));
		map<int,int> pos;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				dp[i][j]=2;
				int diff = A[j]-A[i];
				int need = 2*A[i]-A[j];
				if(pos.find(need)==pos.end()) continue;
				dp[i][j]=max(dp[i][j],dp[pos[need]][i]+1);
			}
			pos[A[i]]=i;
		}
		int ans=2;
		
	}
};

int main() {

	return 0;
}