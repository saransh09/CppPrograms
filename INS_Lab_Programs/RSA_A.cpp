#include<iostream>
using namespace std;

int m_inv(int a,int b){
    int temp=a;
    int t=0,t1=0,t2=1;
    int r=1000;
    while(1){
        if(r==0){
            break;
        }
        r = a%b;
        t = t1 - (a/b)*t2;
        t1 = t2;
        a = b;
        b = r;
        t2 = t;
    }
    if(t1<0){
        return (t1+temp);
    }
    return t1;
}

int prime(int p){
    for(int i=2;i<=p/2;i++){
        if(p%i==0){
            return 0;
        }
    }
    return 1;
}

int calc_phi(int p, int q){
    while(prime(p) && prime(q)){
        return (p-1)*(q-1);
    }
}

void possible_candidates(int phi,int e[],int d[]){
    int j=0;
    for(int i=0;i<phi;i++){
        if(phi%i==0){
            continue;
        }
        if(prime(i)){
            d[j] = i;
            j++;
            continue;
        }
    }
    for(int i=0;e[i]!=0;i++){
        d[i] = m_inv(phi,e[i]);
    }
}




int main(){
    cout<<"Enter two prime numbers : ";
    int p,q;
    cin>>p>>q;
    int e[100],d[100];
    int phi = calc_phi(p,q);
    cout<<phi;
    possible_candidates(phi,e,d);
    return 0;
}
