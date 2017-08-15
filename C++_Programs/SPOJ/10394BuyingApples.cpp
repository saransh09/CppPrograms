#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	vector<int> sol;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> p(k+1);
		for(int i = 1 ; i <=k ; i++) cin>>p[i];
		vector<int> ans(k+1);
		for(int i = 1 ; i <= k ; i++) ans[i] = p[i];
		for(int i = 2 ; i <= k ; i++){
			for(int j = 1 ; j < i ; j++){
				if(p[i-j]==-1 || ans[j] == -1) continue;
				else if(ans[i]==-1) ans[i] = ans[j] + p[i-j];
				else ans[i] = min(ans[i],ans[j]+p[i-j]);
			}
		}
		sol.push_back(ans[k]);
	}
	for(int i = 0 ; i < sol.size() ; i++) cout<<sol[i]<<endl;
	return 0;
}
