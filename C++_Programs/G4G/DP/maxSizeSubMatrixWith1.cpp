#include <bits/stdc++.h>
using namespace std;

class Solution{

public:
	int calcMaxSubMatrixArea(vector<vector<int> > M){
		int R = M.size();
		int C = M[0].size();
		int S[R][C];
		int max_of_s ,max_i, max_j;
		for(int i = 0 ; i < R ; i++) S[i][0] = M[i][0];
		for(int j = 0 ; j < C ; j++) S[0][j] = M[0][j];
		for(int i = 1 ; i < R ; i++){
			for(int j = 1 ; j < C ; j++){
				if(M[i][j]==1) S[i][j] = min(S[i-1][j-1],min(S[i-1][j],S[i][j-1])) + 1;
				else S[i][j]=0;
			}
		}
		max_of_s = S[0][0], max_i = 0 , max_j = 0;
		for(int i = 0 ; i < R ; i++){
			for(int j = 0 ; j < C ; j++){
				if(max_of_s < S[i][j]){
					max_i = i;
					max_j = j;
					max_of_s = S[i][j];
				}
			}
		}
		printf("Maximum size sub-matrix is: \n");
		  for(int i = max_i; i > max_i - max_of_s; i--)
		  {
		    for(int j = max_j; j > max_j - max_of_s; j--)
		    {
		      printf("%d ", M[i][j]);
		    }  
		    printf("\n");
		  }  
		return (max_i - max_of_s)*(max_j - max_of_s);
	}
};

int main() {
	vector<vector<int> > M = {{0, 1, 1, 0, 1}, 
                   			  {1, 1, 0, 1, 0}, 
                   			  {0, 1, 1, 1, 0},
                   			  {1, 1, 1, 1, 0},
                   			  {1, 1, 1, 1, 1},
                   			  {0, 0, 0, 0, 0}};
    Solution s;
    cout<<s.calcMaxSubMatrixArea(M);
	return 0;
}