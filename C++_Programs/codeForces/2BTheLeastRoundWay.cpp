#include <bits/stdc++.h>
#define ll long long
using namespace std;

int fact2(int x){
	int c = 0;
	while(x%2==0){
		c++;
		x /= 2;
	}
	return c;
}

int fact5(int x){
	int c = 0;
	while(x%5==0){
		c++;
		x /= 5;
	}
	return c;
}

int main() {
	int n;
	cin>>n;
	int hv = 0, p, q;
	vector<vector<int> > v(n,vector<int>(n));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			int x;
			cin>>x;
			if(x==0){
				hv = 1;
				p = i;
				q = j;
			}
		}
	}
	vector<vector<vector<int> > > dp(n,vector<vector<int> >(n, vector<int>(2)));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(i==0 && j==0) {
				dp[0][0][0] = fact2(v[i][j]); dp[0][0][1] = fact5(v[i][j]);
			}
			else if(i==0) {
				dp[0][j][0] = fact2(v[i][j]) + dp[0][j-1][0];
				dp[0][j][1] = fact5(v[i][j]) + dp[0][j-1][1];
			}
			else if(j==0) {
				dp[i][0][0] = fact2(v[i][j]) + dp[i-1][0][0];
				dp[i][0][1] = fact5(v[i][j]) + dp[i-1][0][1];	
			}
			else {
				dp[i][j][0] = fact2(v[i][j]) + min(dp[i-1][j][0],dp[i][j-1][0]);
				dp[i][j][1] = fact5(v[i][j]) + min(dp[i-1][j][1],dp[i][j-1][1]);
			}
		}
	}
	string y = "";
	if(dp[n-1][n-1][0] < dp[n-1][n-1][1]){
		int i = n-1;
		int j = n-1;
		while(i+j != 0){
			if(i==0){ y += 'R' ; j-- ;}
			else if(j==0) { y += 'D' ; i-- ;}
			else {
				if(dp[i-1][j][0] < dp[i][j-1][0]){
					i--;
					y += 'D';
				}
				else{
					j--;
					y+='R';
				}
			}
		}
	}
	else{
		int i = n-1;
		int j = n-1;
		while(i+j!=0){
			if(i==0){ y += 'R' ; j-- ;}
			else if(j==0) { y += 'D' ; i-- ;}
			else{
				if(dp[i-1][j][1] < dp[i][j-1][1]){
					i--;
					y+='D';
				}
				else{
					j--;
					y+='R';
				}
			}
		}
	}
	reverse(y.begin(),y.end());
	int ans = min(dp[n-1][n-1][0],dp[n-1][n-1][1]);
	if(ans>0 && hv){
		cout << 1 << endl;
		string z="";
		int e=0;
		while(e!=p){ z+='D';e++;}
		e=0;
		while(e!=n-1){ z+='R';e++;}
		while(p!=n-1){ z+='D';p++;}
		cout << z << endl;
	}
	else{
		cout<< ans << endl << y << endl;
	}
	return 0;
}