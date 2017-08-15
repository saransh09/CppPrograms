#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int lis(const vector<int> & A){
		if(A.size()==0) return 0;
		vector<int> val(A.size(),1);
		int sol=1;
		for(int i=1;i<(int)A.size();i++){
			for(int j=0;j<i;j++){
				if(A[i]>A[j]){
					val[i]=max(val[j]+1,val[i]);
					if(val[i]>sol) sol=val[i];
				}
			}
		}
		return sol;
	}
};

int main() {
	vector<int> v = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
	Solution s;
	cout<<endl<<s.lis(v)<<endl;
	return 0;
}