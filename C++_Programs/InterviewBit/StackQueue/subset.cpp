#include <bits/stdc++.h>
using namespace std;
void generateSubset(vector<int> &s, int index, vector<int> & current, vector<vector<int> > & result) {
	if (index >= s.size()) {
		result.push_back(current);
		return;
	}
	generateSubset(s,index+1,current,result);
	current.push_back(s[index]);
	generateSubset(s,index+1,current,result);
	current.pop_back();
}
vector<vector<int> > Solution(vector<int> &s) {
	vector<vector<int> > result;
	vector<int> current;
	sort(s.begin(), s.end());
	generateSubset(s,0,current,result);
	sort(result.begin(),result.end());
	return result;
}
int main() {

	return 0;
}