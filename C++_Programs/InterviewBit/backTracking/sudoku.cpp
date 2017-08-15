#include<bits/stdc++.h>
using namespace std;

class Solution {
int rowhash[9][9], colhash[9][9], blockhash[3][3][9];
public:
bool solveSudokuHelper(vector<vector<char> > & board, int pos) {
	if (pos>=81) return true;
	int i=pos/9, j=pos%9;
	if (board[i][j]!='.') return solveSudokuHelper(board,pos+1);
	for(int num=0;num<9;num++){
		if(rowhash[i][num]!=1 && colhash[j][num]!=1 && blockhash[i/3][j/3][num]!=1){
			board[i][j]=num+'1';
			rowhash[i][num]=1;
			colhash[j][num]=1;
			blockhash[i/3][j/3][num]=1;
			if (solveSudokuHelper(board,pos+1)) return true;
			board[i][j]=num+'.';
			rowhash[i][num]=0;
			colhash[j][num]=0;
			blockhash[i/3][j/3][num]=0;
		}
	}
	return false;
}
void solveSudoku(vector<vector<char>>& board) {
    memset(rowhash,0,sizeof(rowhash));
    memset(colhash,0,sizeof(colhash));
    memset(blockhash,0,sizeof(blockhash));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
                int num = board[i][j]-'1';
                rowhash[i][num]=1;
                colhash[j][num]=1;
                blockhash[i/3][j/3][num]=1;
            }
        }
    }
    solveSudokuHelper(board,0);
}

};
int main() {

	return 0;
}
