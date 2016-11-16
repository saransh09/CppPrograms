#include<cmath>
#include<iostream>
using namespace std;

long int Alice(long int g,long int n,long int x){
    int k=1;
    for(int j=0;j<x;j++){
        k*= g;
        k = k%n;
    }
    return k;
}

long int Bob(long int g,long int n,long int y){
    int k=1;
    for(int j=0;j<y;j++){
        k*=g;
        k = k%n;
    }
    return k;
}

int main(){
    long int n,g,x,y;
    cout<<"Enter value of n & g : ";
    cin>>n>>g;
    cout<<"\nEnter the values of x & y"<<endl;
    cin>>x>>y;
    long int r1 = Alice(g,n,x);
    long int r2 = Bob(g,n,y);
    cout<<"r1 = "<<r1<<endl<<"r2 = "<<r2<<endl;  //Exchange of keys
    long int k1 = Alice(r2,n,x);
    long int k2 = Bob(r1,n,y);
    if(k1==k2){
        cout<<"keys are exchanged succesfully"<<endl;
        cout<<"Key : "<<k1;
    }
    else{
        cout<<"Keys were not exchanged succesfully";
    }
    return 0;
}
