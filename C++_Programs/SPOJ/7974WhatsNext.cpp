#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1){
		int a,b,c;
		cin>>a>>b>>c;
		if((a==b) && (b==c) && c==0) break;
		// Check for AP
		int d1,d2;
		d1 = b - a;
		d2 = c - b;
		if(d1==d2){ 
			cout<<"AP "<<c+d2<<endl;
			continue;
		}
		// Check for GP
		float r1=0,r2=0;
		if(a!=0) r1 = (float)b/a;
		if(b!=0) r2 = (float)c/b;
		if(r1==r2) cout<<"GP "<<c*r1<<endl; 
	}
	return 0;
}