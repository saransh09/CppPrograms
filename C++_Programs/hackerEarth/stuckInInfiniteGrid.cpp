#include <iostream>
using namespace std;
#define ll long long;

int main(){
    int t;
    cin>>t;
    while(t--){
        int ix, iy, fx, fy, k;
        cin>>ix>>iy>>fx>>fy>>k;
        // cout<<calcPaths(ix,iy,fx,fy,k)<<endl;
        int dx = abs(ix - fx);
        int dy = abs(iy - fy);
        if(((dx+dy)%2==0 && k%2==1) || ((dx + dy)%2==1 && k%2==0)){
            cout<<0<<endl;
            continue;
        }
        if(dx + dy < k) {
            cout<<0<<endl;
            continue;
        }
        if(dx+dy==k){
            if(dx==0 & dy==0){
                cout<<0<<endl;
            }
            if(dx==0){
                cout<<1<<endl;
                continue;
            }
            else if(dy==0){
                cout<<1<<endl;
                continue;
            }
            else{
                cout<<k<<endl;
                continue;
            }
        }
        else{
            
            continue;
        }
    }
}
