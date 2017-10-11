#include <bits/stdc++.h>
using namespace std;

int main() {
	while(!cin.eof()){
		string s;
		cin>>s;
		int i = 0;
		while(s[i]=='0') i++;
		s = s.substr(i,s.size());
		i = s.size()-1;
		while(s[i]=='0') i--;
		s = s.substr(0,i+1);
		reverse(s.begin(),s.end());
		cout<<stoi(s)<<endl;
	}
	return 0;
}