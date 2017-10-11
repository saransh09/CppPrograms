#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> x,y;
    vector<float> dis;
    float m = 0;
    for(int i = 0 ; i < n ; i++){
        int X,Y;
        cin>>X>>Y;
        x.push_back(X);
        y.push_back(Y);
        dis.push_back(sqrt(pow(X,2)+pow(Y,2)));
//        m = max(m,dis[i]);
    }
    sort(dis.begin(),dis.end());
    int count = 0;
    for(int i = 0 ; i < (int)dis.size() ; i++){
        if(count==k){
            break;
        }
        m = dis[i];
        count++;
    }
    cout<<ceil(m)<<endl;
    return 0;
}
