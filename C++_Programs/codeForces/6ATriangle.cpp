#include <bits/stdc++.h>
using namespace std;

bool tr(int a, int b, int c){
	return ((a+b>c) && (a+c>b) && (b+c)>a);
}

bool seg(int a, int b, int c){
	return ((a==b+c)||(b==a+c)||(c==a+b));
}

int main() {
	bool norm = false, deg = false;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	norm = norm || tr(a,b,c);
	norm = norm || tr(a,c,d);
	norm = norm || tr(a,b,d);
	norm = norm || tr(b,c,d);
	deg = deg || seg(a,b,c);
	deg = deg || seg(a,b,d);
  	deg = deg || seg(a,c,d);
  	deg = deg || seg(b,c,d);
  	if(norm) cout<<"TRIANGLE";
  	else if(deg) cout<<"SEGMENT";
  	else cout<<"IMPOSSIBLE";
}