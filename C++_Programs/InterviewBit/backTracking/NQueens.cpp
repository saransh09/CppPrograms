#include <bits/stdc++.h>
using namespace std;

class NQueens{
public:
	vector<string> solToSols(vector<int> sol) {
		int n = sol.size();
		vector<string> sols(n);
		for (int i=0 ; i<n ; i++) {
			sols[i] = string(n,'.');
			sols[i][sol[i]] = 'Q';
		}
		return sols;
	}

	bool isAvailable(int i, int j, vector<int> & sol) {
		for (int k=0 ; k<i ; k++) {
			if (j==sol[k] || i+j==k+sol[k] || i-j==k-sol[k]) return false;
		}
		return true;
	}

	void rSolveNQueens(int row, vector<int> & sol, vector<vector<string> > & sols) {
		int n = sol.size();
		if (row==n) {
			sols.push_back(solToSols(sol));
			return;
		}
		for (int j = 0 ; j < n ; j++) {
			if (isAvailable(row,j,sol)) {
				sol[row] = j;
				rSolveNQueens(row+1,sol,sols);
			}
		}
	}

	vector<vector<string> > Nqueens(int n) {
		vector<int> sol(n);
		vector<vector<string> > sols;
		rSolveNQueens(0,sol,sols);
		return sols;
	}
};

int main() {
	NQueens q;
	vector<vector<string> > v = q.Nqueens(12);
	cout<<endl<<"The number of distinct solutions are : "<<v.size()<<endl<<endl;
	for (int i = 0 ; i < v.size() ; i++) {
		for (int j = 0 ; j < v[i].size() ; j++) {
			cout<<v[i][j]<<endl;
		}
		cout<<endl<<endl;
	}
	return 0;
}