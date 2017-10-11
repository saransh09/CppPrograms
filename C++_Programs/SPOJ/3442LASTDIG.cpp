#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int a;
		unsigned long long int b;
		cin>>a>>b;
		if(a==0) cout<<0<<endl;
		else if(a==1) cout<<1<<endl;
		else if(b==0) cout<<1<<endl;
		else if(b==1) cout<<a<<endl;
		else {
			int temp = b%4;
			if(temp==0) temp = 4;
			cout<<((int)pow(a,(int)(temp)))%10<<endl;
		}
	}
	return 0;
}