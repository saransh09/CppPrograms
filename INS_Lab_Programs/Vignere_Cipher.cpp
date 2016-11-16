#include<string>
#include<iostream>
using namespace std;

class Vignere{
    public:
    string key;

    Vignere(string key){
        for(int i=0;i<key.size();i++){
            if(key[i]>='A' && key[i]<='Z'){
                this->key += key[i];
            }
            else if(key[i]>='a' && key[i]<='z'){
                this->key += key[i] + 'A' - 'a';
            }
        }
    }

    string encrypt(string text){
        string out;
        for(int i=0,j=0;i<text.length();i++){
            char c = text[i];
            if(c>='a' && c<='z'){
                c+= 'A'-'a';
            }
            else if(c<'A' || c>'Z'){
                continue;
            }
            out+=(c+key[j]-2*'A')%26 + 'A';
            j = (j+1)%key.length();
        }
        return out;
    }
};

int main(){
    string key,plaintext;
    cout<<"Enter plaintext : ";
    cin>>plaintext;
    cout<<"Enter key : ";
    cin>>key;
    Vignere cipher(key);
    string encrypted = cipher.encrypt(plaintext);
    cout<<plaintext<<endl;
    cout<<"The encrypted text is : "<<encrypted<<endl;
    return 0;
}
