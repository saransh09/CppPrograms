#include<iostream>
using namespace std;

int m_inv(int a,int b){
    int temp = a;
    int t=0,t1=0,t2=1;
    int r = 1000;
    while(1){
        if(r==0){
            break;
        }
        r = a%b;
        t = t1 - (a/b)*t2;
        a = b;
        t1 = t2;
        b = r;
        t2 = t;
    }
    if(t1<0){
        return (t1+temp);
    }
    return t1;
}

int findX(int *n,int *r,int k){
    int M=1,pm=1;
    for(int i=0;i<k;i++){
        M*=n[i];
    }
    int x=0;
    for(int i=0;i<k;i++){
        pm = M/n[i];
        x += (pm*m_inv(n[i],pm)*r[i]);
    }
    return x%M;
}


int main(){
    int n[10],r[10],k;
    cout<<"Enter the number of elements : ";
    cin>>k;
    cout<<"Enter the numbers : ";
    for(int i=0;i<k;i++){
        cin>>n[i];
    }
    cout<<"Enter the remainders : ";
    for(int i=0;i<k;i++){
        cin>>r[i];
    }
    cout<<"Smallest number possible is : "<<findX(n,r,k);
    return 0;
}
