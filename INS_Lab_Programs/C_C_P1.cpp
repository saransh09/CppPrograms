#include<string>
#include<iostream>
using namespace std;

int length(char * a){
    int i=0;
    while(a[i]!='\0'){
        i++;
    }
    return i;
}

string enc_cc(char *a,char *b,int key){
    for(int i=0;i<length(a);i++){
        if(a[i]==' '){
            b[i] = ' ';
        }
        else if(int(a[i])>=65 && int(a[i])<97){
            b[i] = char(int(a[i]+key-65)%26+ 65);
        }
        else{
            b[i] = char(int(a[i] + key - 97)%26 + 97);
        }
    }
}

int main(){
    char a[100],b[100];
    cout<<"Enter the plaintext : ";
    cin.getline(a,100);
    cout<<"Enter the key : ";
    int k;
    cin>>k;
    enc_cc(a,b,k);
    cout<<b;
    return 0;
}
