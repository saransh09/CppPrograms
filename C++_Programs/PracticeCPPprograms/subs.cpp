#include<string.h>
#include<iostream>
using namespace std;

void print_substr_rec(char *a,char* sol,int N,int size)
{
    if(N==0){
        for(int i=0;i<size;i++){
            cout<<sol[i];
        }
        cout<<endl;
        return;
    }

    print_substr_rec(a+1,sol,N-1,size);
    sol[size]=*a;
    print_substr_rec(a+1,sol,N-1,size+1);
    return;
}

int main()
{
    char a[100],sol[100];
    cin.getline(a,100);
    int N = strlen(a);
    print_substr_rec(a,sol,N,0);
    return 0;
}
