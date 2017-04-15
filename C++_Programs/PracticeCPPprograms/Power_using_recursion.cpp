#include<iostream>
using namespace std;

long long int calc_pow_rec(int a,int x)
{
    if(x==1)
        return a;
    else if(x%2==1)
        return x*calc_pow_rec(a,x/2)*calc_pow_rec(a,x/2);
    else if(x%2==0)
        return calc_pow_rec(a,x/2)*calc_pow_rec(a,x/2);
}

int main()
{
    cout<<"Enter the number and the power which has to be computed : ";
    int a,x;
    cin>>a>>x;
    cout<<"The power is : "<<calc_pow_rec(a,x);
    return 0;
}
