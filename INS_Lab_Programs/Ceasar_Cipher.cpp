#include<string>
#include<iostream>
using namespace std;


string encrypt(string text,int s){
    string result = "";
    for(int i=0;i<text.length();i++){
        if(isspace(text[i])){
            result += " ";
        }
        else if(isupper(text[i])){
            result += char(int(text[i]+s-65)%26+ 65);
        }
        else{
            result += char(int(text[i] + s - 97)%26 + 97);
        }
    }
    return result;
}

int main(){
    char text[100];
    int k;
    cout<<"Enter the text : ";
    cin.getline(text,100);
    cout<<"\nEnter the key : ";
    cin>>k;
    cout<<"The Cypher text is : "<<encrypt(text,k)<<endl;
    return 0;
}
