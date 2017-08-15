#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
	vector<string> solToSols(vector<int> sol){
		int n = sol.size();
		vector<string> sols(n);
		for(int i=0;i<n;i++){
			sols[i] = string('.',n);
			sols[i][sol[i]] = 'Q';
		}
		return sols;
	}
	bool isAvailable(int i, int j, vector<int> & sol){
		for(int k=0; k<i ; k++){
			if(j==sol[k] || i+j == k+sol[k] || i-j==k-sol[k]) return false;
		}
		return true;
	}
	void rSolveNQueens(int row, vector<int> sol, vector<vector<string> > sols){
		int n = sol.size();
		if(row==n){
			sols.push_back(solToSols(sol));
			return;
		}
		for(int j=0;j<n;j++){
			if(isAvailable(row,j,sol)){
				sol[row]=j;
				rSolveNQueens(row+1,sol,sols);
			}
		}
	}
public:
	vector<vector<string> > NQueens(int n){
		vector<vector<string> > sols;
		vector<int> sol(n);
		rSolveNQueens(0,sol,sols);
		return sols;
	}
};

int main() {
	Solution s;
	vector<vector<string> > v = s.NQueens(8);
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<endl;
		}
		cout<<endl;
	}
	return 0;
}