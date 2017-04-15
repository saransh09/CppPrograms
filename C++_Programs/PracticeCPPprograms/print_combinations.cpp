#include<iostream>
using namespace std;

void print_combos(int *a,int *sol,int N,int size,int sum,int val)
{
    if(sum==val){
        for(int i=0;i<size;i++){
            cout<<sol[i]<<' ';
        }
        cout<<endl;
        return;
    }
    if(sum>val){
        return;
    }
    if(N==0 && sum!=val){
        return;
    }
    print_combos(a+1,sol,N-1,size,sum,val);
    sol[size]=*a;
    print_combos(a+1,sol,N-1,size+1,sum+*a,val);
}

int main()
{
    int sol[100];
    int a[6] = {1,2,3,4,5,6};
    print_combos(a,sol,6,0,0,6);
    return 0;
}
