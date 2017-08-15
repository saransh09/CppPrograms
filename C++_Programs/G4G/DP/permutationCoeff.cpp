#include <bits/stdc++.h>
using namespace std;

class Solution{
	long long permuteDP1(int n, int k){
		long long P[n+1][k+1];
		for(int i = 0 ; i <= n ; i++){
			for(int j = 0 ; j <= min(i,k) ; j++){
				if(j==0) P[i][j] = 1;
				else P[i][j] = P[i-1][j] + (j*P[i-1][j-1]);
				P[i][j+1] = 0;
			}
		}
		return P[n][k];
	}
	long long permuteDP2(int n, int k){
		int fact[n+1];
		fact[0] = 1;
		for(int i = 1 ; i <= n ; i++) fact[i] = i*fact[i-1];
		return fact[n]/fact[n-k];
	}
public:
	long long permute(int n, int k){
		return permuteDP1(n,k);
	}
};

int main() {
	int n,k;
	cin>>n>>k;
	Solution s;
	cout<<s.permute(n,k)<<endl;
	return 0;
}