#include <bits/stdc++.h>
using namespace std;

void permute(string & a, vector<string> & v, int i){
	if(i==(int)a.size()){
		v.push_back(a);
	}
	for(int j=i;j<a.size();j++){
		swap(a[i],a[j]);
		permute(a,v,i+1);
		swap(a[i],a[j]);
	}
}

int main() {
	string a;
	a = "abc";
	vector<string> v;
	permute(a,v,0);
	for(int i = 0 ; i < (int)v.size() ; i++){
		cout<<v[i]<<endl;
	}
	return 0;
}