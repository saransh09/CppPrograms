#include<iostream>
using namespace std;

int calc_no_of_possible_steps(int n,int x)
{
    if(x==n-1)
    {
        return 1;
    }
    else if(x==n-2)
    {
        return 1;
    }
    else if(x==n-3)
    {
        return 1;
    }
    else
    {
        return calc_no_of_possible_steps(n,x+1) + calc_no_of_possible_steps(n,x+2) + calc_no_of_possible_steps(n,x+3);
    }
}

int calc_no_of_possible_steps_bu(int n)
{
    if(n==1)
    {
        return 1;
    }
    else if(n==2)
    {
        return 2;
    }
    else if(n==3)
    {
        return 4;
    }
    else
    {
        return calc_no_of_possible_steps_bu(n-1) + calc_no_of_possible_steps_bu(n-2) + calc_no_of_possible_steps_bu(n-3);
    }
}

int main()
{
    cout<<"Enter the number of steps in the staircase : ";
    int n;
    cin>>n;
    cout<<"The number of possible steps are : "<<calc_no_of_possible_steps_bu(n);
    return 0;
}
