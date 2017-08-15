string Solution::addBinary(string A, string B) {
    // long long int a = atoi(A);
    // long long int b = atoi(B);
    int n1 = A.size();
    int n2 = B.size();
    string sol;
    int carry = 0;
    int i,j;
    if (n1 > n2) {
        for (i = n2 - 1, j = n1 - 1 ; i >= 0 ; i--,j--) {
            if (B[i]=='0' && A[j]=='0') {
                if (carry==0) sol += '0';
                else if (carry = 1) {
                    sol += '1';
                    carry = 0;
                }
                
            }
            else if ((B[i]=='0' && A[j]=='1') || (B[i]=='1' && A[j]=='0')) {
                if (carry == 0) sol += '1';
                else if (carry == 1) {
                    sol += '0';
                    carry = 0;
                }
            }
            else {
                if (carry==0) {
                    sol += '0';
                    carry = 1;
                }
                else {
                    sol += '1';
                    carry = 1;
                }
            }
        }
        if(i==j) {
            reverse(sol.begin(),sol.end());
            return sol;
        }
        else {
            if (carry == 0) {
                if (A[j]=='0') {
                    sol += '0';
                }
                else {
                    A[j]=='1';
                    sol += '1';
                }
                j--;
                while(j>=0) {
                    sol += A[j];
                    j--;
                }
                reverse(sol.begin(),sol.end());
                return sol;
            }
            else {
                if (A[j]=='0') {
                    sol += '1';
                    carry = 0;
                }
                else {
                    A[j]=='1';
                    sol += '0';
                    carry = 1;
                }
                j--;
                while(j>=0) {
                    if (carry == 0) {
                        sol += A[j];
                        j--;
                    }
                    else {
                        if (A[j]=='0') {
                            sol += '1';
                            carry = 0;
                            j--;
                        }
                        else {
                            sol += '0';
                            carry = 1;
                            j--;
                        }
                    }
                }
                reverse(sol.begin(),sol.end());
                return sol;
            }
        }
    }
    else {
        for (i = n2 - 1, j = n1 - 1 ; i >= 0 ; i--,j--) {
            if (A[i]=='0' && B[j]=='0') {
                if (carry==0) sol += '0';
                else if (carry = 1) {
                    sol += '1';
                    carry = 0;
                }
                
            }
            else if ((A[i]=='0' && B[j]=='1') || (A[i]=='1' && B[j]=='0')) {
                if (carry == 0) sol += '1';
                else if (carry == 1) {
                    sol += '0';
                    carry = 0;
                }
            }
            else {
                if (carry==0) {
                    sol += '0';
                    carry = 1;
                }
                else {
                    sol += '1';
                    carry = 1;
                }
            }
        }
        if(i==j) {
            reverse(sol.begin(),sol.end());
            return sol;
        }
        else {
            if (carry == 0) {
                if (B[j]=='0') {
                    sol += '0';
                }
                else {
                    B[j]=='1';
                    sol += '1';
                }
                j--;
                while(j>=0) {
                    sol += B[j];
                    j--;
                }
                reverse(sol.begin(),sol.end());
                return sol;
            }
            else {
                if (B[j]=='0') {
                    sol += '1';
                    carry = 0;
                }
                else {
                    B[j]=='1';
                    sol += '0';
                    carry = 1;
                }
                j--;
                while(j>=0) {
                    if (carry == 0) {
                        sol += B[j];
                        j--;
                    }
                    else {
                        if (B[j]=='0') {
                            sol += '1';
                            carry = 0;
                            j--;
                        }
                        else {
                            sol += '0';
                            carry = 1;
                            j--;
                        }
                    }
                }
                reverse(sol.begin(),sol.end());
                return sol;
            }
        }
    }
    return sol;
    
}
