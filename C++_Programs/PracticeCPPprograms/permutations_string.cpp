#include<string.h>
#include<iostream>
using namespace std;

void swap(char *x,char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a,int l,int r){

    if(l==r){
        cout<<a<<endl;
        return;
    }

    for(int i=l;i<=r;i++){
        swap(a+l,a+i);
        permute(a,l+1,r);
        swap(a+l,a+i);

    }
    return;
}

int main()
{
    char a[] = "abcd";
    //cin.getline(a,100);
    int n = strlen(a);
    permute(a,0,n-1);
    return 0;
}
