#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
	int lbsHelper(vector<int> & s,vector<int> & inc, vector<int> & dec, int n){
		for(int i=1;i<n;i++){
			for(int j=i-1;j>=0;j--){
				if(s[i]>s[j] && inc[i]<inc[j]+1) inc[i] = inc[j] + 1;
			}
		}
		for(int i=n-2; i>0 ; i--){
			for(int j=i+1; j<n; j++){
				if(s[i]>s[j] && dec[i]<dec[j]+1) dec[i] = dec[j] + 1;
			}
		}
		int mx=0;
		for(int i=0 ; i<n; i++){
			mx = max(mx,inc[i]+dec[i]-1);
		}
		return mx;
	}
public:
	int lbs(vector<int> & s){
		int n = s.size();
		vector<int> inc(n,1), dec(n,1);
		return lbsHelper(s,inc,dec,n);
	}
};

int main() {

	return 0;
}