string Solution::countAndSay(int A) {
    if (A == 1) {
        return "1";
    }
    string temp = "1";
    int i = 0, j = 0;
    for (int z = 1 ; z < A ; z++) {
        // int x = z;
        // while(x!=0) {
        //     temp += char(x%10)+0;
        //     x /= 10;
        // }
        // int i=0,j=0;
        string sol;
        for (i = 0 ; i < temp.size() ; i++) {
            j=1;
            while(temp[i+j]==temp[i] && i+j<temp.size()-1) {
                j++;
            }
            char ch = char(j)+'0';
            sol += ch;
            sol += temp[i];
            i=j;
        }
        temp = sol;
    }
    return temp;
}
