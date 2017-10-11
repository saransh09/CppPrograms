#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	unordered_map<string,int> m;
	pair<string,int> currMax;
	currMax.first = "";
	currMax.second = 0;
	for(int i = 0 ; i < n ; i++){
		pair<string,int> p;
		cin>>p.first>>p.second;
		if(m.find(p.first)==m.end()){
			m[p.first] = p.second;
		}
		else{
			m[p.first] += p.second;
		}
		if(m[p.first] > currMax.second) {
			currMax.first  = p.first;
			currMax.second = m[p.first];
		}
	}
	cout<<currMax.first<<endl;
	return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
string s[1001];
int i,m,n,o[1001];
map<string,int>p,t;
main(){
cin>>n;
for(;i<n;i++)cin>>s[i]>>o[i],p[s[i]]+=o[i];
for(i=0;i<n;i++)m=max(m,p[s[i]]);
for(i=0;p[s[i]]<m||(t[s[i]]+=o[i])<m;i++);
cout<<s[i];
}
*/