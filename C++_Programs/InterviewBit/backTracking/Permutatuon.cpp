#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	void permuteHelper(vector<int> & A, int index, vector<vector<int> > & sol) {
		if (index==A.size()-1) {
			sol.push_back(A);
			return;
		}
		for (int i = index ; i < A.size() ; i++) {
			swap(A[index],A[i]);
			permuteHelper(A,index+1,sol);
			swap(A[index],A[i]);
		}
		return;
	}
	vector<vector<int> > permute(vector<int> & A) {
		vector<vector<int> > sol;
		sort(A.begin(),A.end());
		permuteHelper(A,0,sol);
		// sort(sol.begin(),sol.end());
		return sol;
	}
};

int main() {
	vector<int> v = {1,2,3};
	Solution S;
	vector<vector<int> > sol = S.permute(v);
	for (int i = 0 ; i < sol.size() ; i++) {
		for (int j = 0 ; j < sol[i].size() ; j++) {
			cout<<sol[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}