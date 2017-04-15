#include<string.h>
#include<iostream>
using namespace std;

void print_sunstrings_bu(char *a,char *sol,int N,int size){
    if(N==0){
        for(int i=0;i<size;i++)
            cout<<sol[i];

        cout<<endl;
        return;
    }

    print_sunstrings_bu(a+1,sol,N-1,size);
    sol[size] = *a;
    print_sunstrings_bu(a+1,sol,N-1,size+1);
    return;
}

void print_sunstrings_td(char *a,char *sol,int N,int size){

    if(a[size]=='\0'){
        cout<<sol;
        return;
    }

    sol[size]='\0';
    print_sunstrings_td(a+1,sol,N+1,size);
    sol[size]=*a;
    sol[size+1]='\0';
    print_sunstrings_td(a+1,sol,N+1,size);
    return;
}

int main()
{
    char arr[100];
    cin.getline(arr,100);
    char sol[100];
    //print_sunstrings_bu(arr,sol,strlen(arr),0);
    print_sunstrings_td(arr,sol,strlen(arr),0);
    return 0;
}
