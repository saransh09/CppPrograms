#include <bits/stdc++.h>
using namespace std;

void combSumHelper(vector<int> & num, int index, int sum, vector<vector<int> > & sol, vector<int> & curr){
    if(sum==0){
    	vector<int> temp = curr;
    	sort(temp.begin(),temp.end());
        sol.push_back(temp);
        return;
    }
    if(sum<0 || index==num.size()) return;
    curr.push_back(num[index]);
    combSumHelper(num,index+1,sum-num[index],sol,curr);
    curr.pop_back();
    combSumHelper(num,index+1,sum,sol,curr);
}

vector<vector<int> > combSum(vector<int> num, int sum) {
    vector<vector<int> > sol;
    vector<int> curr;
    combSumHelper(num,0,sum,sol,curr);
    sort(sol.begin(),sol.end());
    sol.erase(unique(sol.begin(),sol.end()),sol.end());
    return sol;
}

int main() {
	int t;
	cin>>t;
	int n[t];
	vector<vector<int> > nums(t);
	int sum[t];
	for(int i = 0 ; i < t ; i++){
	    cin>>n[i];
	    for(int j = 0 ; j < n[i] ; j++) {
	        int x;
	        cin>>x;
	        nums[i].push_back(x);
	    }
	    cin>>sum[i];
	}
	for(int i = 0 ; i < t ; i++) {
	    vector<int> num = nums[i];
	    vector<vector<int> > sol = combSum(num,sum[i]);
	    if(sol.empty()){ 
	        cout<<"Empty"<<endl;
	        continue;
	    }
	    for(int j = 0 ; j < sol.size() ; j++) {
	        cout<<"(";
	        for(int k = 0 ; k < sol[j].size() ; k++) {
	            cout<<sol[j][k];
	            if(k==sol[j].size()-1) continue;
	            cout<<' ';
	        }
	        cout<<")";
	    }
	    cout<<endl;
	}
	return 0;
}