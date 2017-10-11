#include <bits/stdc++.h>
using namespace std;

int minDistance(vector<int> loc, int n, int c){
	
}

int main() {
	int t;
	cin>>t;
	int n,c;
	cin>>n>>c;
	vector<int> loc(n);
	for(int i = 0 ; i < n ; i++) cin>>loc[i];
	sort(loc.begin(),loc.end());
	return minDistance(loc,n,c);
	return 0;
}