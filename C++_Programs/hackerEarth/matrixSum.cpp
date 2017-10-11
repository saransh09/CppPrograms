#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > mat(n,vector<int>(m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int x;
            cin>>x;
            mat[i][j] = x;
        }
    }
    // int q;
    // cin>>q;
    vector<vector<int> > dp(n+1,vector<int>(m+1));
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            if(i==0 || j==0) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mat[i-1][j-1];
        }
    }
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= m ; j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }
    // while(q--){
    //     int x,y;
    //     cin>>x>>y;
    //     cout<<dp[x-1][y-1]<<endl;
    // }
}