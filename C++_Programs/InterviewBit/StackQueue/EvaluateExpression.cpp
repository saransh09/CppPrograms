nclude<stack>
int Solution::evalRPN(vector<string> &A) {
    for(int z = 0; z < A.size(); z++) {
        stack<int> S;
        string a = A[z];
        int i=0;
        while(a[i]!='\0') {
            if (a[i]=='+') {
                int t1 = S.top();
                S.pop();
                int t2 = S.top();
                S.pop();
                S.push(t1+t2);
            }
            else if (a[i]=='-') {
                int t1 = S.top();
                S.pop();
                int t2 = S.top();
                S.pop();
                S.push(t1-t2);
            }
            else if (a[i]=='*') {
                int t1 = S.top();
                S.pop();
                int t2 = S.top();
                S.pop();
                S.push(t1*t2);
            }
            else if (a[i]=='/') {
                int t1 = S.top();
                S.pop();
                int t2 = S.top();
                S.pop();
                S.push(t2/t1);
            }
            else {
                S.push(a[i]);
            }
            i++;
        }
    }
}

