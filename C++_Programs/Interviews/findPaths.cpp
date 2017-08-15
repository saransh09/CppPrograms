#include <bits/stdc++.h>
using namespace std;

int findPathsHelper(int n, int m, int x, int y){
    if(x==n-1 || y==m-1) return 1;
    else return findPathsHelper(n,m,x+1,y) + findPathsHelper(n,m,x,y+1);
}

int findPaths(int n, int m){
    return findPathsHelper(n,m, 0, 0);
}

int main() {
    int t;
    cin>>t;
    pair<int,int> p[t];
    for(int i = 0 ; i < t ; i++) {
        cin>>p[i].first>>p[i].second;
    }
    for(int i=0; i<t ; i++){
        cout<<findPaths(p[i].first,p[i].second)<<endl;
    }
	return 0;
}