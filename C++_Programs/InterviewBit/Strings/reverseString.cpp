#include <bits/stdc++.h>
using namespace std;

void reverseWords(string &A) {
    stack<string> S;
    int i = 0,j = 0;
    string temp;
    while(A[i]!='\0') {
        j = i;
        temp = "";
        // cout<<i<<' ';
        while(A[i]!=' ' && A[i]!='\0') {
            i++;
        }
        // cout<<i<<' '<<endl;
        temp = A.substr(j,i-j);
        // cout<<endl<<temp<<endl;
        S.push(temp);
        cout<<S.top()<<endl;
        if (A[i]=='\0') {
            break;
        }
        i++;
    }
    string sol;
    while(!S.empty()) {
        sol += S.top();
        S.pop();
        if (!S.empty()) {
            sol += " ";
        }
    }
    A.empty();
    A = sol;
}

int main() {
    string a = "fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq";
    cout<<"String before reversing words : ";
    cout<<endl<<a<<endl<<"String after reversing words : "<<endl;
    reverseWords(a);
    cout<<a;
    return 0;
}