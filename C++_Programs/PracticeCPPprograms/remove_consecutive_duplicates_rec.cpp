#include<iostream>
#include<string.h>
using namespace std;

void rem_consec_duplicates_rec(char *a,int b,int e,char *c,int i)
{
    if(b>=e)
        return;

    if(a[b]!=a[b+1])
    {
        c[i] = a[b];
        return rem_consec_duplicates_rec(a,b+1,e,c,i+1);
    }

    if(a[b]==a[b+1])
    {
        c[i] = a[b];
        if(b!=e-1)
        {
            return rem_consec_duplicates_rec(a,b+2,e,c,i+1);
        }
        else
        {
            c[i] = a[b];
            return;
        }

    }


}

int main()
{
    char a[100],c[100];
    cout<<"Enter the string : ";
    cin.getline(a,100);
    int e = strlen(a)-1;
    rem_consec_duplicates_rec(a,0,e,c,0);
    cout<<endl<<endl<<c;
    return 0;
}
