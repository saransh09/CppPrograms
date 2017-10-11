#include <bits/stdc++.h>
using namespace std;

int check(int x, int y){
	// There are two lines, y = x and y = x - 2
	if(x==y){
		if(x%2==0) return 2*x;
		else return 2*x-1;
	}
	else if(x==y+2){
		if(x%2==0) return 2*x-2;
		else return 2*x-3;
	}
	else return -1;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		int ans = check(x,y);
		if(ans==-1) cout<<"No Number"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}