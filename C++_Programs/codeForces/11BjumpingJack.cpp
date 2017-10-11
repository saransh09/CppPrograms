#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i;
	cin>>n;
	int x = 0;
	if(n<0) n *= -1;
	for(i = 0 ; i < 1000000000 ; i++){
		x += i;
		if(x%2==n%2 && x>=n) break;
	}
	cout<<i;
	return 0;
}