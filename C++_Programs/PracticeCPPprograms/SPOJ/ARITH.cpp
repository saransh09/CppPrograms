#include <bits/stdc++.h>
using namespace std;

int main() {
	string s = "3817189371298371298+131838237618736";
	int i = 0;
	while(s[i]!='+' && s[i]!='-' && s[i]!= '*') {
		i++;
	}
	string n1 = s.substr(0,19);
	// cout<<endl<<n1<<endl;
	while(s[i]!='\0') {
		i++;
	}
	string n2 = s.substr(20,i);
	int l1 = n1.length();
	int l2 = n2.length();
	if (l1 > l2) {
		string copy(n2);
		reverse(copy.begin(),copy.end());
		copy.resize(l1,' ');
		// cout<<copy;
		reverse(copy.begin(),copy.end());
		// cout<<copy;
		n2 = copy;
	}
	cout<<n1<<endl<<n2;
	return 0;
}