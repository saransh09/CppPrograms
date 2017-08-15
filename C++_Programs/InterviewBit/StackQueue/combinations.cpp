#include <bits/stdc++.h>
using namespace std;
void combineHelper(vector<int> current, int n, int k, vector<vector<int> > ans) {
	if (k==0) {
		vector<int> newEntry = current;
		ans.push_back(newEntry);
		return;
	}
	if (n==0 || n<k) {
		return;
	}
	// Do not include n
	combineHelper(current, n-1, k, ans);
	// Include n
	current.push_back(n);
	combineHelper(current, n-1, k-1, ans);
	current.pop_back();
	return;
}
vector<vector<int> > combine(int n, int k) {
    vector<vector<int> > ans;
    vector<int> current;
    combineHelper(current, n, k, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
	vector<vector<int> > v = combine(5,2);
	vector<vector<int> >::iterator it = v.begin();
	while(it!=v.end()) {
		vector<int> temp = *it;
		for(int i = 0; i<temp.size();i++) {
			cout<<temp[i];
		}
		cout<<endl;
		it++;
	}
	return 0;
}