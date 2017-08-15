#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x, y;
};

class Solution{
public:
	// list<Point> findPath(vector<vector<int> > grid, vector<vector<)
	void findSnakePathSequence(vector<vector<int> > mat){
		int M = mat.size();
		int N = mat[0].size();
		int lookup[M][N];
		memset(lookup,0,sizeof(lookup));
		int max_len = 0, max_row = 0, max_col = 0;
		for(int i = 0 ; i < M ; i++){
			for(int j = 0 ; j < N ; j++){
				if(i || j){
					
				}
			}
		}
	}
};


int main() {

	return 0;
}