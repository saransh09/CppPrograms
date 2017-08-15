#include<stack>
#include<queue>
int Solution::braces(string A) {
    stack s;
    int i=0;
    while(A[i]!='\0') {
        if(A[i]==')') {
            while(s.top()!='(') {
                s.pop();
            }
            if(A[i+1]==')' && A[i+1]!='\0' && s.top()=='(') {
                return 0;
            }
        }
        else {
            s.push(A[i]);
        }
        i++;
    }
    return 1;
}

