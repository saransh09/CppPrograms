#include <bits/stdc++.h>
using namespace std;

int main() {
	string A = "cool_ice_wifi";
	unordered_set<string> goodWords;
	for (int i = 0 ; A[i]!='\0' ;) {
        while(A[i]==' '){
        	i++;
        	cout<<"i = "<<i<<endl;	
        } 
        while (A[i]=='_') {
        	i++;
        	cout<<"i = "<<i<<endl;
        }
        int j = i+1;
        while( A[j]!='\0' && A[j]!='_') {
        	j++;
        	cout<<"j = "<<j<<endl;
        }
        cout<<"i = "<<i<<"    j = "<<j<<endl;
        string word = A.substr(i,j-i);
        cout<<"i = "<<i<<endl;
        cout<<'\t'<<word<<'\t'<<endl;
        goodWords.insert(word);
        i = j+1;
    }
    auto it = goodWords.begin();
    while(it!=goodWords.end()) {
    	cout<<*it<<' ';
    	it++;
    }
    vector<vector<string> > B ;
    // {"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};
    B.push_back({"water_is_cool"});
    B.push_back({"cold_ice_drink"});
    B.push_back({"cool_wifi_speed"});
    vector<int> ans;
    for (int i = 0 ; i < B.size() ; i++) {
        string review = B[i];
        int count = 0;
        for (int j = 0 ; review[j]!='\0' ;) {
            while(review[j]==' ') j++;
            while (review[j]=='_') j++;
            int k = j;
            while(A[k]!='_' && A[k]!='\0') k++;
            string word = A.substr(j,k-j);
            if (goodWords.find(word)!=goodWords.end()) {
                count++;
            }
            j = k+1;
        }
        ans.push_back(count);
    }
    cout<<endl<<endl<<endl<<"ANSWER IS : "<<endl;
    for (int i = 0 ; i < ans.size() ; i++) {
    	cout<<ans[i]<<' ';
    }
	return 0;
}