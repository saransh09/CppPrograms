#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n , p1,p2,p3,t1,t2;
int last , ans ;

int main(){

cin>>n>>p1>>p2>>p3>>t1>>t2;

for(int i=0;i<n;i++){

    int l,r;
    cin>>l>>r;

    if( !i )last=l;

    if( l-last < t1 )
            ans+=(l-last)*p1;
    else
    if( l-last < t1+t2 )
            ans+=t1*p1 + (l-last-t1)*p2;
    else
        ans+= t1*p1 + t2*p2 + (l-last-t1-t2)*p3;

    ans+=(r-l)*p1;
    last=r;
}

cout<<ans<<endl;
return 0;
}