#include <bits/stdc++.h>
using namespace std;

class Solution {

	bool isAvailable(int i, int j, vector<int> sol) {
		for (int k=0 ; k<sol.size() ; k++) {
			if (j==sol[k] || i+j==k+sol[k] || i-j==k-sol[k]) return false;
		}
		return true;
	}

	rRowQueens(int row, vector<int> & sol, vector<vector<string> > & sols) {
		int n = sol.size();
		if (row==n) {
			sols.push_back(sol);
			return;
		}
		for (int j=0 ; j < n ; j++) {
			if (isAvailable(row,j,sol)) {
				sol[row] = j;
				rSolveQueens(row+1,sol,sols);
			}
		}
	}

	vector<vector<string> > NQueens(int n) {
		vector<vector<string> > sols;
		vector<int> sol(n);
		rRowQueens(0,sol,sols);
		return sols;
	}
};