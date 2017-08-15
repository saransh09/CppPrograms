#include <bits/stdc++.h>
using namespace std;
void subsetsWithDupHelper(vector<vector<int> > & sol, int index, vector<int> & A, vector<int> & current) {
    if (index == A.size() ) {
        sol.push_back(current);
        return;
    }
    // subsetWithDupHelper(sol,index+1, A, current);
    // current.push_back(A[i]);
    subsetWithDuphelper(sol,index,A,current);
    current.push_back(A[i]);
    currentWithDupHelper(sol,index+1,A+1,current);
    current.pop_back(A[i]);
}

vector<vector<int> > subsetsWithDup(vector<int> &A) {
    vector<vector<int> > sol;
    vector<int> v;
    sort(A.begin(),A.end());
    vector<int> current;
    return subsetwithDupHelper(sol,0,A,current);
}

int main() {

	return 0;
}