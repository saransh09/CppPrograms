#include <bits/stdc++.h>
using namespace std;

int main() {
	int i = 124124;
	string a;
	while(i>0) {
		char ch = i%10 + '0';
		// cout<<ch;
		// cout<<a;
		cout<<endl<<int(ch)-'0'<<endl;
		i = i/10;
	}
	// cout<<endl<<ch;
	return 0;
}