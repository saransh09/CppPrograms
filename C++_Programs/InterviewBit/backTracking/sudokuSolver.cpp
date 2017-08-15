#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int rowhash[9][9], colhash[9][9], blockhash[3][3][9];

        bool solveSudoku(vector<vector<char> > &board, int position) {
            if (position >= 9*9) {
                return true;
            }
            int row = position / 9, col = position % 9;
            if (board[row][col] != '.') {
                return solveSudoku(board, position + 1);
            }
            for (int num = 0; num < 9; num++) {
                if (rowhash[row][num] != 1 && colhash[col][num] != 1 && blockhash[row / 3][col / 3][num] != 1) {
                    // Include num in the solution 
                    board[row][col] = '1' + num;
                    rowhash[row][num] = 1;
                    colhash[col][num] = 1;
                    blockhash[row / 3][col / 3][num] = 1;
                    if (solveSudoku(board, position + 1)) return true;
                    // Reset
                    board[row][col] = '.';
                    rowhash[row][num] = 0;
                    colhash[col][num] = 0;
                    blockhash[row / 3][col / 3][num] = 0;
                }
            }
            return false;
        }

        void solveSudoku(vector<vector<char> > &board) {
            memset(rowhash, 0, sizeof(rowhash));
            memset(colhash, 0, sizeof(colhash));
            memset(blockhash, 0, sizeof(blockhash));
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (board[i][j] != '.') {
                        int num = board[i][j] - '1';
                        rowhash[i][num] = 1;
                        colhash[j][num] = 1;
                        blockhash[i / 3][j / 3][num] = 1;
                    }
                }
            }
            solveSudoku(board, 0);
        }
};

int main() {
	vector<vector<char> > sud = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};
	Solution s;
	s.solveSudoku(sud);
	for (int i = 0 ; i < 9 ; i++) {
		for (int j = 0; j < 9 ; j++) {
			cout<<sud[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}