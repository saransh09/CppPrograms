#include <bits/stdc++.h>
using namespace std;

class Permutations{
public:
	void rPermute(vector<int> & A, int index, vector<vector<int> > & sol) {
		if (index==A.size()-1) {
			sol.push_back(A);
			return;
		}
		for (int i = index ; i < A.size() - 1 ; i++) {
			swap(A[index],A[i]);
			rPermute(A,index+1,sol);
			swap(A[index],A[i]);
		}
	}
	vector<vector<int> > permutations(vector<int> & A) {
		vector<vector<int> > sol;
		sort(A.begin(),A.end());
		rPermute(A,0,sol);
		return sol;
	}
};

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(6);
	v.push_back(4);
	Permutations p;
	vector<vector<int> > sol = p.permutations(v);
	for (int i = 0 ; i < sol.size() ; i++) {
		for (int j = 0 ; j < sol[j].size() ; j++) {
			cout<<sol[i][j];
		}
		cout<<endl;
	}
	return 0;
}