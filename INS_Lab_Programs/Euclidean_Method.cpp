#include<iostream>
using namespace std;

int gcd(int  a, int  b){
    int t = a%b;
    while(t){
        if(b==0){
            break;
        }
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    cout<<gcd(4192,128);
}
