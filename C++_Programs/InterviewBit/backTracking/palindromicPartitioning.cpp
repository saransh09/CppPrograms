#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isPalindrome(int i, int j, string s){
	    while(i<j){
	        if(s[i]!=s[j])
	            return false;
	        i++;
	        j--;
	    }
	    return true;
	}
	void generatePartitionHelper(int i, vector<string>&current,string &s,vector<vector<string>>&ans){
	    if(i>=s.length()){
	        ans.push_back(current);
	        return;
	    }
	    for(int j=i;j<s.length();++j){
	        if(isPalindrome(i,j,s)){
	            current.push_back(s.substr(i,j-i+1));
	            generatePartitionHelper(j+1,current,s,ans);
	            current.pop_back();
	        }
	    }
	}
	vector<vector<string> > partition(string A) {
	    
	    vector<vector<string>>ans;
	    vector<string>current;
	    generatePartitionHelper(0,current,A,ans);
	    return ans;
	}
};

int main() {
	string s = "aab";
	Solution S;
	vector<vector<string> > sol = S.partition(s);
	for (int i = 0 ; i < sol.size() ; i++) {
		for (int j = 0 ; j < sol[i].size() ; j++) {
			cout<<sol[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}