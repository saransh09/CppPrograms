#include<iostream>
using namespace std;


//TOP DOWN APPROACH :
int calc_paths_recursively(int m,int n,int x,int y)
{
    if(x==m-1 || y==n-1)
    {
        return 1;
    }
    else
    {
        return calc_paths_recursively(m,n,x+1,y) + calc_paths_recursively(m,n,x,y+1);
    }
}

//BOTTOM UP APPROACH :
int calc_paths_recursively_bu(int m,int n,int x,int y)
{
    int c[m][n];
    if(x==1 || y==1)
    {
        return 1;
    }
    else
    {
        return calc_paths_recursively_bu(m,n,x-1,y) + calc_paths_recursively_bu(m,n,x,y-1);
    }
}

int main()
{
    cout<<"Enter the number of rows and columns of the matrix : ";
    int n,m;
    cin>>m>>n;
    cout<<"The possible paths are : "<<calc_paths_recursively_bu(m,n,0,0);
}
