#include <bits/stdc++.h>
using namespace std;

string complexNumberMultiply(string a, string b) {
        pair<int,int> fcn,scn;
        // for (int i = 0 ; i < a.size() ;) {
        int i = 0;
        bool flag = false;
        int j = i;
        while(a[j]!='+') j++;
        fcn.first = stoi(a.substr(i,j-i));
        j++;
        if (a[j]=='-') {flag = true;
        ++j;}
        i = j;
        while(a[j]!='i') j++;
        fcn.second = stoi(a.substr(i,j-i));
        if (flag==true) fcn.second *= -1;
        // break;
        // }
        // for (int i = 0 ; i < b.size() ;) {
        i = 0;
        flag = false;
        j = i;
        while(b[j]!='+') j++;
        scn.first = stoi(b.substr(i,j-i));
        j++;
        if (b[j]=='-') {flag = true;
        ++j;}
        i = j;
        while(b[j]!='i') j++;
        scn.second = stoi(b.substr(i,j-i));
        if (flag==true) scn.second *= -1;
        // break;
        // }
        pair<int,int> fa;
        fa.first = fcn.first*scn.first + (-1)*fcn.second*scn.second;
        fa.second = fcn.first*scn.second + fcn.second*scn.first;
        string ans;
        ans += to_string(fa.first);
        ans += '+';
        ans += to_string(fa.second);
        ans += to_string('i');
        return ans;
}

int main() {
	string a = "1+1i";
	string b = "1-1i";
	cout<<complexNumberMultiply(a,b);
	// pair<int,int> fcn,scn;
	// for (int i = 0 ; i < a.size() ;) {
 //        bool flag = false;
 //        int j = i;
 //        while(a[j]!='+') j++;
 //        // fcn.first = stoi(a.substr(i,j-i));
 //        cout<<"j-i = "<<j-i<<endl;
 //        ++j;
 //        cout<<"a[j] = "<<a[j]<<endl;
 //        if (a[j]=='-') {flag = true; ++j;}
 //        cout<<"a[j] = "<<a[j]<<endl;
 //        i = j;
 //        while(a[j]!='i') j++;
 //        cout<<"j-i = "<<j-i<<endl;
 //        cout<<"a[j] = "<<a[j]<<endl;
 //        // fcn.second = stoi(a.substr(i,j-i));
 //        if (flag==true) fcn.second *= -1;
 //        break;
	// }
	return 0;
}