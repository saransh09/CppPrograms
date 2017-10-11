#include <bits/stdc++.h>
using namespace std;

void subSetSumHelper(vector<int> s, int a, int b, vector<int> curr, int sum ,int index, int & count){
	if(index==s.size()){
		if(sum>=a && sum<=b) 
	}
	subSetSumHelper(s,a,b,curr,index+1,count);
	curr.push_back(s[index]);
	subSetSumHelper(s,a,b,curr,index+1,count);
	curr.pop_back();
}

int subSet(vector<int> s, int a, int b){
	vector<int> curr;
	int count = 0;
	subSetSumHelper(s,a,b,curr,0,0,count);
	return count;
}

int main() {
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> s(n);
	for(int i = 0 ; i < n ; i++) cin>>s[i];
	cout<<subSet(s,a,b);
	return 0;
}