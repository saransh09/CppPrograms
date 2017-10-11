#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x;
	cin>>n>>x;
	vector<pair<int,int> > v;
	for(int i = 0 ; i < n ; i++){
		int a,b;
		cin>>a>>b;
		if(a>b){
			v.push_back(make_pair(b,a));
		}
		else{
			v.push_back(make_pair(a,b));
		}
	}
	int m = INT_MIN, M = INT_MAX;
	for(int i = 0 ; i < n ; i++){
		m = max(m,v[i].first);
		M = min(M,v[i].second);
	}
	if(m>M) cout<<-1;
	else if(x>=m && x<=M) cout<<0;
	else if(x<m) cout<<m-x;
	else if(x>M) cout<<x-M;
	return 0;
}