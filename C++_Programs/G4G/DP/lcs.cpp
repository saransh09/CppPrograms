#include <bits/stdc++.h>
using namespace std;

class Solution{
	int lcsHelper(string a, string b, int m, int n){
		if(m==0 || n==0) return 0;
		else if(a[m-1]==b[n-1]) return 1 + lcsHelper(a,b,m-1,n-1);
		else return max(lcsHelper(a,b,m-1,n),lcsHelper(a,b,m,n-1));
	}
	int lcsHelperDP(string a, string b){
		int L[a.length()+1][b.length()+1];
		for(int i = 0 ; i <= (int)a.size() ; i++){
			for(int j = 0 ; j <= (int)b.size() ; j++){
				if(i==0 || j==0) L[i][j]=0;
				else if(a[i-1]==b[j-1]) L[i][j] = L[i-1][j-1]+1;
				else L[i][j] = max(L[i-1][j],L[i][j-1]);
			}
		}
		return L[a.size()][b.size()];
	}
public:
	int lcs(string a, string b){
		// return lcsHelper(a,b,a.length(),b.length());
		return lcsHelperDP(a,b);
	}
};

int main() {
	string a = "abcdeasjdnhaojsfhnoisadgiughisfhiaghiadghsoughsdfuoggfguafdssufashufdashsadupfhuasdasiofhaiodfhpidsahhfasupifdhf";
	string b = "dabcasdjhadjhasodhaoisdjisajdoqjrquirfkjzxmvnzcmvnoadaoijfpoqjfopeatopeajashakcmnsfsdifjsdiofjsoidfjsofjsjfid";
	Solution s;
	cout<<s.lcs(a,b)<<endl;
	return 0;
}