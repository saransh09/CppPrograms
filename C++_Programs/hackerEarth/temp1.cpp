#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int caseNumber = 1;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0 ; i < n ; i++) cin>>arr[i];
        int dp[n+1];
        dp[0] = 0;
        dp[1] = arr[0];
        for(int i = 2 ; i <= n ; i++){
            dp[i] = max(dp[i-2]+arr[i-1],dp[i-1]);
        }
        cout<<"Case "<<caseNumber<<":"<<' '<<dp[n]<<endl;
        caseNumber++;
    }
}
