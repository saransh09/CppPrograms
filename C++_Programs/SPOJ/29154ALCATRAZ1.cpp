#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i = 0 ; i < t ; i++){
		string s;
		cin>>s;
		long long sum = 0;
		for(int i = 0 ; s[i] != '\0' ; i++){
			sum += s[i] - '0';
		}
		cout<<sum<<endl;
	}
	return 0;
}