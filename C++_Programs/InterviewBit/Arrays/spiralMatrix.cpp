#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<vector<int> > generateMatrix(int A) {
    vector<vector<int> > sol;
    vector<int> v;
    if (A==1) {
    	v.push_back(1);
    	sol.push_back(v);
    	return sol;
    }
    v.push_back(0);
    v.resize(A,0);
    for ( int i = 0 ; i < A ; i++ ) {
        sol.push_back(v);
    }
    int ctr = 1;
    int top = 0, right = (A-1), left = 0, bottom = (A-1);
    for (int z = 0 ; left < right ; z++) {
        for (int i = left; i <= right ; i ++) {
            sol[top][i] = ctr++; 
        }
        top++;
        for (int i = top ; i <= bottom ; i++ ) {
            sol[i][right] = ctr++;
        }
        right--;
        for (int i = right; i >= left ; i--) {
            sol[bottom][i] = ctr++;
        }
        bottom--;
        for (int i = bottom; i >= top ; i--) {
            sol[i][left] = ctr++;
        }
        left++;   
    }
    return sol;
}

int main() {
	vector<vector<int> > sol = generateMatrix(1000);
	for (int i = 0 ; i < sol.size() ; i++) {
		for (int j = 0 ; j < sol.size() ; j++) {
			cout<<sol[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}