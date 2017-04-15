#include<iostream>
using namespace std;

void calc_zeros_recur(int x,int sum)
{
    if(x=0)
        return;
    if(x%10==0)
        sum++;

    calc_zeros_recur(x/10,sum);
}

int main()
{
    cout<<"Enter a number to count the number of zeros in : ";
    int x,sum;
    cin>>x;
    calc_zeros_recur(x/10,sum);
    cout<<"The number of zeros in the given integer are : "<<sum;
    return 0;
}
