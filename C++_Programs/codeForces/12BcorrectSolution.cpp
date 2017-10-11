#include <bits/stdc++.h>
using namespace std;

int main() {
	string s,a;
	cin>>s>>a;
	sort(s.begin(),s.end());
	if(s.length()!=1){
		if(a[0]=='0') swap(a[0],a[1]);
	}
	if(s==a) cout<<"OK";
	else cout<<"WRONG_ANSWER";
}