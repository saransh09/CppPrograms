#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
 
class Solution{
public:
    string solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F);
};
 
#define pii pair<int,int>
 
int par[1000+5];
int rnk[1000+5];
bool vis[1000+5];
 
void initialise(){
    for(int i=0;i<=1000;i++){
        par[i]=i;
        rnk[i]=1;
        vis[i]=false;
    }
}
 
int findPar(int node){
    if(par[node]==node)return node;
    return par[node]=findPar(par[node]);
}
 
void makeUnion(int a,int b){
    int parA=findPar(a);
    int parB=findPar(b);
 
    if(parA==parB)return;
    if(rnk[parA]<rnk[parB])par[parB]=parA;
    else if(rnk[parB]<rnk[parA])par[parA]=parB;
    else{
        rnk[parA]++;
        par[parB]=parA;
    }
}
 
 
bool findBlockage(int root,int X,int Y,int N,int R,vector<pair<int,pii>>vec){
    int top=0;
    int bottom=INT_MAX;
    int left=INT_MAX;
    int right=0;
 
    for(int i=0;i<N;i++){
        if(par[vec[i].first]==root){
            int x=vec[i].second.first;
            int y=vec[i].second.second;
            top=max(top,y+R);
            bottom=min(bottom,y-R);
            left=min(left,x-R);
            right=max(right,x+R);
        }
    }
    if(top>=Y and bottom<=0)return true;
    if(right>=X and left<=0)return true;
    if(top>=Y and right>=X)return true;
    if(left<=0 and bottom<=0)return true;
    return false;
}
 
string Solution::solve(int X, int Y, int N, int R, vector<int> &E, vector<int> &F) {
    vector<pair<int,pii>> vec;
    int id=0;
    for(int i=0;i<N;i++){
        vec.push_back({id,{E[i],F[i]}});
        id++;
    }
 
    initialise();
 
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(i==j)continue;
            int x1=vec[i].second.first;
            int x2=vec[j].second.first;
 
            int y1=vec[i].second.second;
            int y2=vec[j].second.second;
 
            if(((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) <= (4*R*R)){
                makeUnion(vec[i].first,vec[j].first);
            }
        }
    }
 
    for(int i=0;i<N;i++){
        if(!vis[par[vec[i].first]]){
            vis[par[vec[i].first]]=1;
            bool ret = findBlockage(par[vec[i].first],X,Y,N,R,vec);
            if(ret)return "NO";
        }
    }
    return "YES";
}
 
int main(){
    int n,x,y,r;
    cin>>x>>y>>n>>r;
    vector<int>X(n);
    vector<int>Y(n);
 
    for(int i=0;i<n;i++)cin>>X[i];
    for(int i=0;i<n;i++)cin>>Y[i];
 
    Solution sol;
    cout<<sol.solve(n,x,y,r,X,Y)<<endl;
}