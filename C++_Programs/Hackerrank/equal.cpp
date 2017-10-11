#include <bits/stdc++.h>
using namespace std;

void incrementBy(vector<int> & v, int k, int j){
	for(int i = 0 ; i < (int)v.size() ; i++){
		if(i==j) continue;
		else v[i] += k;
	}
}



int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v;
		int m = INT_MAX;
		for(int i = 0 ; i < n ; i++){
			int x;
			cin>>x;
			m = min(m,x);
			v.push_back(x);
		}
		for(int i = 0 ; i < n-1 ; i++){
			v[i] -= m;
		}
		int sol = -1;
		for(int i = 0 ; i < n ; i++){
			if(v[i]==0) continue;
			else{
				while(v[i]>=5) {
					v[i] -= 5;
					sol++;
				}
				if(v[i]==0){
					continue;
				} 
				else if(v[i]==1){
					sol++;
					v[i] -= 1;
					continue;
				}
				else if(v[i]==2){
					sol++;
					v[i] -= 2;
					continue;
				}
				else if(v[i]==3){
					sol += 2;
					v[i] -= 3;
					continue;
				}
				else if(v[i]==4){
					sol += 2;
					v[i] -= 4;
					continue;
				}
			}
		}
		cout<<sol<<endl;
	}
	return 0;
}