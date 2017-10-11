#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int arr[n];
    bool fav[n];
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    unordered_set<int> favNums;
    for(int i = 0 ; i < k ; i++){
        int x;
        cin>>x;
        favNums.insert(x);
    }
    for(int i = 0 ; i < n ; i++){
        if(favNums.find(arr[i])!=favNums.end()) fav[i] = true;
        else fav[i] = false;
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        for(int i = a - 1 ; i < b - 1 ; i++){
            if(!fav[i]) {
                arr[i] -= c;
                if(favNums.find(arr[i])!=favNums.end()) fav[i] = true;
            }
        }
        cout<<endl;
        for(int i = 0 ; i < n ; i++) cout<<arr[i]<<' ';
        cout<<endl;
        int sum = 0;
        for(int i = 0 ; i < n ; i++) sum += arr[i];
        cout<<sum<<endl;
    }
    return 0;
}
