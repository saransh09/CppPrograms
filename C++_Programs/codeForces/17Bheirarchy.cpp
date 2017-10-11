#include <bits/stdc++.h>
using namespace std;
const int maxn = 1006;
const int inf = 1e9;
int c[maxn],n,m;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        c[i]=inf;
    int id=0,play=0;
    for(int i=1;i<=n;i++){
        int p;
        scanf("%d",&p);
        if(p>play){
            play=p;
            id=i;
        }
    }
    c[id]=0;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        c[B]=min(c[B],C);
    }
    long long ans = 0;
    for(int i=1;i<=n;i++){
        if(c[i]==inf){
            printf("-1\n");
            return 0;
        }
        ans += c[i];
    }
    cout<<ans<<endl;
}