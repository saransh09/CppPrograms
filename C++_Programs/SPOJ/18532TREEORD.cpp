#include <bits/stdc++.h>
using namespace std;

string DetermineIfBTree(vector<int> pre, vector<int> post, vector<int> in){
	bool check;
	
}

int main() {
	int n;
	cin>>n;
	vector<int> pre,post,in;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin>>x;
		pre.push_back(x);
	}
	for(int i = 0 ; i < n ; i++){
		int x;
		cin>>x;
		post.push_back(x);
	}
	for(int i = 0 ; i < n ; i++){
		int x;
		cin>>x;
		in.push_back(x);
	}
	cout<<DetermineIfBTree(pre,post,in);
	return 0;
}