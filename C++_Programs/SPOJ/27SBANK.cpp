#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	map<list<string>,int> m[t];
	for(int i = 0 ; i < t ; i++){
		int n;
		cin>>n;
		for(int j = 0 ; j < n ; j++){
			list<string> ban;
			for(int z = 0 ; z < 6 ; z++){
				string x;
				cin>>x;
				ban.push_back(x);
			}
			if(m[i].find(ban)==m[i].end()){
				m[i][ban] = 1;
			}
			else{
				m[i][ban] += 1;
			}
		}
	}
	cout<<endl;
	for(int i = 0 ; i < t ; i++){
		for(auto it = m[i].begin() ; it!=m[i].end() ; it++){
				for(auto it1 = it->first.begin() ; it1 != it->first.end() ; it1++){
					cout<<*it1<<' ';
				}
				cout<<it -> second << endl;
		}
		cout<<endl;
	}
	return 0;
}