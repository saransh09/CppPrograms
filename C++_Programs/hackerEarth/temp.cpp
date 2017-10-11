#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> > &A) 
{
    if(A[0][0]==1) return 0;
    int m=A.size();
    int n=A[0].size();
    int V[m][n];
    V[0][0]=1;
    int i=1;
    bool f=0,f1=0;
    while(i<n){
        if(A[0][i]==1){
            f=1;
            V[0][i]=0;
        }
        else V[0][i]=1;
        
        i++;
        if(f==1)
        break;
    }
    while(i<n){
        V[0][i]=0;
        i++;
    }
    int j=1;
    while(j<m){
        if(A[j][0]==1){
            f1=1;
            V[j][0]=0;
        }
        else V[j][0]=1;
        j++;
        if(f1==1) break;
    }
    while(j<n){
        V[j][0]=0;
        j++;
    }
    for(int k=1;k<m;k++){
        for(int l=1;l<n;l++){
          if(A[k][l]==1)
          V[k][l]=0;
          else
          V[k][l]=V[k-1][l]+V[l-1][k];
        }
    }
    return V[m-1][n-1];
}


int main() {
	vector<vector<int> > v = {{1,0,1,0},
							  {1,1,0,1},
							  {1,1,1,1},
							  {0,0,0,0},
							  {0,1,1,1},
							  {0,0,1,1},
							  {1,0,0,1}};
    cout<<uniquePathsWithObstacles(v);
}