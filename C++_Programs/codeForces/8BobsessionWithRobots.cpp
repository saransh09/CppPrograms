#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> m;

bool check(int x, int y, int i){
	return m[make_pair(x,y)] && m[make_pair(x,y)]!=i+1;
}

int main() {
	string s;
	cin>>s;
	int x=0,y=0;
	m[make_pair(x,y)] = 1;
	for(int i = 0 ; i < (int)s.size() ; i++){
		if(s[i]=='U') y++;
		else if(s[i]=='D') y--;
		else if(s[i]=='R') x++;
		else if(s[i]=='L') x--;
		if(check(x,y,i),check(x-1,y,i),check(x+1,y,i),check(x,y-1,i),check(x,y+1,i)){
			cout<<"BUG"<<endl;
			return 0;
		}
		m[make_pair(x,y)] = i + 2;
	}
	cout<<""
	return 0;
}