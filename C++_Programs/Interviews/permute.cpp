#include <bits/stdc++.h>
using namespace std;

void permuteHelper(string & s, int index, vector<string> & sol){
    if(index==s.size()-1){
        sol.push_back(s);
        return;
    }
    for(int i = index ; i < s.size() ; i++){
        swap(s[index],s[i]);
        permuteHelper(s,index+1,sol);
        swap(s[index],s[i]);
    }
}

vector<string> permute(string & s){
    vector<string> sol;
    permuteHelper(s,0,sol);
    return sol;
}

int main() {
	int t;
	cin>>t;
	string s[t];
	for(int i = 0 ; i < t ; i++) cin>>s[i];
	for(int i = 0 ; i < t ; i++){
	    vector<string> sol = permute(s[i]);
	    for(int j = 0 ; j < sol.size() ; j++) cout<<sol[j]<<' ';
	}
	return 0;
}
