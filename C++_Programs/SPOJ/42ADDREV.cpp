#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	pair<int,int> p[t];
	for(int i = 0 ; i < t ; i++) {
		cin>>p[i].first>>p[i].second;
	}
	for(int i = 0 ; i < t ; i++) {
		string a = to_string(p[i].first);
		string b = to_string(p[i].second);
		reverse(a.begin(),a.end());
		reverse(b.begin(), b.end());
		string c = to_string(stoi(a) + stoi(b));
		reverse(c.begin(),c.end());
		cout<<stoi(c)<<endl;
	}
	return 0;
}