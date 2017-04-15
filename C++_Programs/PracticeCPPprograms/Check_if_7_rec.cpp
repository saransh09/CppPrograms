#include<iostream>
using namespace std;

bool Check_if_7(int *a,int s,int e)
{
    if(s>=e)
        return false;

    if(a[s]==7)
        return true;

    Check_if_7(a,s+1,e);
}

int main()
{
    int a[6] = {1,3,4,5,-8,9};
    cout<<Check_if_7(a,0,5);
    return 0;
}
