#include<iostream>
#include<string>
using namespace std;

int len(char *key){
    int i=0;
    while(key[i]!='\0'){
        i++;
    }
    return i;
}

void encrypt(char *pt,char *key,char *e){
        int j=0;
        while(pt[j]!='\0'){
            for(int i=0;i<len(key);i++){
                if(pt[j]=='\0'){
                    break;
                }
                if(int(pt[j])>=65 && int(pt[j])<97){
                    e[j] = char((int((pt[j]) +key[i] - 65)%26)+65);
                }
                j++;
        }
    }
    e[j+1]='\0';
}
int main(){
    char pt[100],key[100],e[100];
    cin.getline(pt,100);
    cin.getline(key,100);
    encrypt(pt,key,e);
    for(int i=0;i<len(e);i++){
        cout<<e[i];
    }
    return 0;
}
