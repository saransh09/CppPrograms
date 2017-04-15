#include<iostream>
#include<string.h>
using namespace std;

void rev_string_rec(char *a,int b,int e)
{
    char x;
    if(b>=e)
        return;
    else
    {
        a[b]=x;
        a[b]=a[e];
        a[e]=x;
    }

    rev_string_rec(a,b+1,e-1);

}

int main()
{
    char a[5];
    cin.getline(a,5);
    rev_string_rec(a,0,3);
    cout<<a;
    return 0;
}
