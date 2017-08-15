void findComb(vector<int> & A, int index, int sum, vector<vector<int> > & sol, vector<int> & current) {
    if (sum<0) return;
    if (sum==0) {
        sol.push_back(current);
        return;
    }
    if (index >= A.size()) return;
    current.push_back(A[index]);
    findComb(A,index+1,sum-A[index],sol,current);
    current.pop_back();
    while(index<A.size()-1 && A[index]==A[index+1]) index++;
    findComb(A,index+1,sum,sol,current);
    return;
}

vector<vector<int> > Solution::combinationSum(vector<int> & A, int B) {
    vector<vector<int> > sol;
    vector<int> current;
    sort(A.begin(),A.end());
    findComb(A,0,B,sol,current);
    sol.erase(unique(sol.begin(),sol.end()),sol.end());
    sort(sol.begin(),sol.end());
    return sol;
}


// void findCombinations(vector<int> & A, int index, int sum, vector<vector<int> > & sol, vector<int> & current) {
//     if (sum < 0) return;
//     if (sum == 0) {
//         // if (!sol.empty() && isSameVectors(current,sol.front())) return;
//         sol.push_back(current);
//         return;
//     }
//     if (index >= A.size()) return;
//     current.push_back(A[index]);
//     findCombinations(A,index+1,sum-A[index],sol,current);
//     current.pop_back();
//     while (index < A.size() - 1 && A[index]==A[index]+1) index++;
//     findCombinations(A,index+1,sum,sol,current);
//     return;
// }

// vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
//     vector<vector<int> > sol;
//     vector<int> current;
//     sort(A.begin(),A.end());
//     findCombinations(A,0,B,sol,current);
//     sort(sol.begin(),sol.end());
//     sol.erase(unique(sol.begin(),sol.end()),sol.end());
//     return sol;
// }
