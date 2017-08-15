#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int longestBitonicSubsequence(vector<int> & A){
		int n = A.size();
	    vector<int> inc(n,1), dec(n,1);
	    for(int i=1; i<n; i++){
	        for(int j=i-1; j>=0; j--)
	        {
	            if(A[i] > A[j] && inc[i] < inc[j] + 1)
	                inc[i] = inc[j] + 1;
	        }
	    }
	    for(int i=n-2; i>=0; i--){
	        for(int j=i+1; j<n; j++)
	        {
	            if(A[i] > A[j] && dec[i] < dec[j] + 1)
	                dec[i] = dec[j] + 1;
	        }
	    }
	    int mx = 0;
	    for(int i=0; i<n; i++)
	        mx = max(mx, inc[i] + dec[i] - 1);

	    return mx;
	}
};

int main() {
	vector<int> v = {1,11,2,10,4,5,2,1};
	Solution s;
	cout<<s.longestBitonicSubsequence(v);
	return 0;
}