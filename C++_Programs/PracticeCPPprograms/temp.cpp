int Solution::trap(const vector<int> &A) {
    int m;
    stack<int> S;
    int m2 = -1;
    int trapped = 0;
    if (A.size()==0 || A.size()==1) {
        return 0;
    }
    m = A[0];
    int i = 1;
    while(i<A.size()) {
        while(i<A.size() && A[i]<m) {
            if (A[i]>m2) {
                m2 = A[i];
            }
            S.push(A[i]);
            i++;
        }
        if (i==A.size()) {
            if (A[i-1]<m) {
                m = m2;
            } 
            while(!S.empty()) {
                int t = S.top();
                trapped += m - t;
                S.pop();
            }
            if (A[i-1]<m) {
                trapped--;
            }
            return trapped;
        }
        else {
            if (A[i]<m) {
                m = m2;
            }
            while(!S.empty()) {
                int t = S.top();
                trapped += (m - t);
                S.pop();
            }
            m = A[i];
            i++;
        }
    }
    return trapped;
}
