#include <bits/stdc++.h>
using namespace std;

vector<int> maxset(vector<int> &A) {
    vector<int>::iterator it = A.begin();
    vector<int>::iterator it2;
    while(*it<0) {
        it++;
    }
    vector<int>::iterator itb;
    vector<int>::iterator ite;
    int maxSum = INT_MIN;
    for (it; it!=A.end();) {
        int sum = 0;
        for (it2 = it ; (*it2 >= 0) ; it2++) {
        	sum += *it2;
        	if (it2 == A.end()) {
        		sum += *it2;
        		break;
        	}
        	vector<int>::iterator temp = it2;
        	temp += 1;
        	if (*temp<0) {
        		break;
        	}
        }
        if (maxSum < sum) {
            maxSum = sum;
            itb = it;
            if (it2 == A.end()) {
                ite = it2;
            }
            else {
                ite = --it2;   
            }
        }
        else if (maxSum == sum) {
            int a = 0;
            vector<int>::iterator temp = it;
            while(temp!=it2) {
                a++;
            }
            int b = 0;
            temp = itb;
            while(temp!=ite) {
                b++;
            }
            if (a > b) {
                itb = it;
                ite = it2;
            }
            else if (a==b) {
                if (*it > *itb) {
                    itb = it;
                    ite = it2;
                }
            }
        }
        if (it2 != A.end()) {
            vector<int>::iterator temp = it2;
            temp = temp + 1;
            if (temp!= A.end()) {
                it2 += 2;
                it = it2;   
            }
        }
    }
    vector<int> sol;
    while(itb != ite) {
        sol.push_back(*itb);
        itb++;
    }
    return sol;
}

int main() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(-7);
	v.push_back(2);
	v.push_back(5);
	vector<int> sol = maxset(v);
	vector<int>::iterator it = sol.begin();
	for (it; it!=sol.end() ; it++) {
		cout<<(*it)<<' ';
	}
	return 0;
}