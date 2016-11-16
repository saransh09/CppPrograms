#include<iostream>
using namespace std;

int m_inv(int a, int b){
    int temp = a;
    int t=0,t1=0,t2=1;
    while(1){
        if(b==0){
            break;
        }
        int r = a%b;
        t = t1 - (a/b)*t2;
        a = b;
        t1 = t2;
        b = r;
        t2 = t;
    }
    if(t1<0){
        return(t1+temp);
    }
    return t1;
}

int main(){
    cout<<"Enter the number and m : ";
    int a,m;
    cin>>a>>m;
    cout<<"modular multiplicative inverse is : "<<m_inv(m,a);
    return 0;
}
