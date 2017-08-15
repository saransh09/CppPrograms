#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int countSubstrings(string s){
		int n = s.length();
		int count=0;
		vector<vector<int> > dp(n,vector<int>(n));
		for(int end=0;end<n;end++){
			dp[end][end]=1;
			count++;
			for(int start=0;start<end;++start){
				if (s[start]==s[end] && (start+1>=end-1 || dp[start+1][end-1])){
					dp[start][end]=1;
					count++;
				}
			}
		}
		return count;
	}
};

int main() {
	string s = "abaoksnijasbdiuasbfiausfbasonoiasnd";
	Solution S;
	cout<<S.countSubstrings(s); 
	return 0;
}