#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int> &A, int B) {
    unordered_map<int,int> m;
    vector<int> ans;
    for (int i = 0 ; i < A.size() ; i++) {
    	int req = B - A[i];
    	if (m.find(req)!=m.end()) {
    		ans.push_back(m[req]);
    		ans.push_back(i+1);
    		return ans;
    	}
    	else {
    		m[A[i]] = i+1;
    	}
    }
}

int main() {
	vector<int> v = {4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
	vector<int> sol = twoSum(v,-3);
	for (int i = 0 ; i < sol.size() ; i++) cout<<sol[i]<<' ';
	cout<<endl;
	return 0;
} 