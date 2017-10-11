#include <bits/stdc++.h>
using namespace std;

bool hall[100][100];
int dp[100][100];
int yt[100][100];
int n,k;

void build(){
	for(int i = 0 ; i < k ; i++){
		int cnt = 0;
		for(int j = 0 ; j < k ; j++){
			if(hall[i][j]){
				dp[i][j] = 0;
				cnt = 0;
			}
			else{
				cnt++;
				dp[i][j] = cnt;
			}
		}
	}
}

int main() {
	cin>>n>>k;
	int xc = k>>1, yc = k>>1;
	for(int i = 0 ; i < k ; i++){
		int total = 0;
		for(int j = i ; j >= 0 ; j--){
			total += abs(yc-j);
			yt[i][j] = total;
		}
	}
	for(int i = 0 ; i < n ; i++){
		int m; cin>>m;
		build();
		
	}
	return 0;
}