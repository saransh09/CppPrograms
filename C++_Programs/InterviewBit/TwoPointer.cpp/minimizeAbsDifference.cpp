vector<int> sol;
    if (A[0] > B[0]) {
        if (A[0] > C[0]) {
            int i = 0;
            while(C[i]<A[0] && i<C.size()) {
                i++;
            }
            int j = 0;
            while(B[j]<A[0] && j<B.size()) {
                j++;
            }
            sol.push_back(A[0]);
            if (j==B.size()-1 || B[j]==A[0]) {
                sol.push_back(B[j]);
            }
            else {
                sol.push_back(B[j-1]);
            }
            if (i==C.size()-1 || C[i]==A[0]) {
                sol.push_back(C[i]);
            }
            else {
                sol.push_back(C[i-1]);
            }
        }
        else {
            int i = 0;
            while(A[i]<C[0] && i<A.size()) {
                i++;
            }
            int j = 0;
            while(B[j]<C[0] && j< B.size()) {
                j++;
            }
            if (i==A.size()-1 || A[i]==C[0]) {
                sol.push_back(A[i]);
            }
            else {
                sol.push_back(A[i-1]);
            }
            if (j==B.size()-1 || B[j]==C[0]) {
                sol.push_back(B[j]);
            }
            else {
                sol.push_back(B[j-1]);
            }
            sol.push_back(C[0]);
        }
    }
    else {
        if (B[0] > C[0]) {
            int i = 0;
            while(C[i]<B[0] && i < C.size()) {
                i++;
            }
            int j = 0;
            while(A[j]<B[0] && j < A.size()) {
                j++;
            }
            if (j==A.size()-1 || A[j]==B[0]) {
                sol.push_back(A[j]);
            }
            else {
                sol.push_back(A[j-1]);
            }
            sol.push_back(B[0]);
            if (i==C.size()-1 || C[i]==B[0]) {
                sol.push_back(C[i]);
            }
            else {
                sol.push_back(C[i-1]);
            }
        }
        else {
            int i = 0;
            while(B[i]<C[0]) {
                i++;
            }
            int j = 0;
            while(A[j]<C[0]) {
                j++;
            }
            if (j==A.size()-1 || A[j]==C[0]) {
                sol.push_back(A[j]);
            }
            else {
                sol.push_back(A[j-1]);
            }
            if (i==B.size()-1 || B[i]==C[0]) {
                sol.push_back(B[i]);
            }
            else {
                sol.push_back(B[i-1]);
            }
            sol.push_back(C[0]);
        }
    }
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0 ; i < 3 ; i++) {
        if (sol[i]>max) {
            max = sol[i];
        }
        if (sol[i]<min) {
            min = sol[i];
        }
    }
    return abs(max - min);