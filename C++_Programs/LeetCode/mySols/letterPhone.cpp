vector<string> charmap = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void generateHelper(string &current, int index, string &digits, vector<string> &ans){
    if(index==digits.length()){
        ans.push_back(current);
        return;
    }
    
    int digit = digits[index]-'0';
    
    for(int i=0;i<charmap[digit].length();i++){
        current.push_back(charmap[digit][i]);
        generateHelper(current,index+1,digits,ans);
        current.pop_back();
    }
    return;
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> sol;
    string current = "";
    generateHelper(current,0,A,sol);
    return sol;
}
