#include <bits/stdc++.h>
using namespace std;

int main() {
	for(;;){
		int n; cin>>n; if(n==0) return 0;
		set<string> uw;
		for(int i = 0 ; i < n ; i++) {
			string s;
			cin>>s;
			uw.insert(s);
		}
		for(;;){
			string acro ; cin>>acro ; cin.ignore();
			string phrase; getline(cin,phrase);
			if(phrase=="CASE") break;
			isstringstream iss(phrase);
			vector<string> words;
			for(;;){
				string word ; iss >> word;
				if(word==" ") break;
				if(uw.find(word)==uw.end()) words.push_back(word);
			}
		}
		int dp[151][151] ; memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		int dp2[151][151];
		for(int i = 0 ; i < words.size() ; i++){
			for(int j = 0; j < acro.length() ; j++){
				int mx = min(acro.length()-j,words[i].length());
				for(int k = 0 ; k <= words[i])
			}
		}
	}
}