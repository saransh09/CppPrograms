#include <bits/stdc++.h>
using namespace std;

class area{
	int a,b;
public:
	area(int a, int b) : a(a), b(b) {}
	friend class Solution;
};

class Solution{
	int Max(int a, int b, int c){
		return max(a,max(b,c));
	}
	int maxSurvivalHelper(int A, int B, area X, area Y, area Z, int last, map<pair<int,int>,int> & memo){
		if(A<=0 || B<=0) return 0;
		pair<int,int> curr = make_pair(A,B);
		if(memo.find(curr)!=memo.end()) return memo[curr];
		int temp;
		switch(last){
			case 1:
				temp = 1 + max(maxSurvivalHelper(A+Y.a,B+Y.b,X,Y,Z,2,memo),maxSurvivalHelper(A+Z.a,B+Z.b,X,Y,Z,3,memo));
				break;
			case 2:
				temp = 1 + max(maxSurvivalHelper(A+X.a,B+X.b,X,Y,Z,1,memo),maxSurvivalHelper(A+Z.a,B+Z.b,X,Y,Z,3,memo));
				break;
			case 3:
				temp = 1 + max(maxSurvivalHelper(A+X.a,B+X.b,X,Y,Z,1,memo),maxSurvivalHelper(A+Y.a,B+Y.b,X,Y,Z,2,memo));
				break;
		}
		memo[curr] = temp;
		return temp;
	}
public:
	int getMaxSurvivalTime(int A, int B, area X, area Y, area Z){
		if(A<=0 || B<=0) return 0;
		map<pair<int,int>,int> memo;
		return Max(maxSurvivalHelper(A+X.a,B+X.b,X,Y,Z,1,memo),maxSurvivalHelper(A+Y.a,B+Y.b,X,Y,Z,2,memo),maxSurvivalHelper(A+Z.a,B+Z.b,X,Y,Z,3,memo));
	}
};

int main() {
	area X(3, 2);
    area Y(-5, -10);
    area Z(-20, 5);
 
    int A = 20;
    int B = 8;
    Solution s;
    cout << s.getMaxSurvivalTime(A, B, X, Y, Z) << endl;
 
    return 0;
}