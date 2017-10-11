#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	// if(s.length()<k){
	// 	cout<<"NO";
	// 	return 0;
	// }
	unordered_map<char,int> m;
	for(int i = 0 ; i < s.length() ; i++){
		if(m.find(s[i])==m.end()){
			m[s[i]] = 1;
		}
		else{
			m[s[i]] += 1;
		}
	}
	for(auto it = m.begin() ; it != m.end() ; it++){
		if(it->second > k) {
			cout<<"NO";
			return 0;
		}

	}
	cout<<"YES";
	return 0;
}