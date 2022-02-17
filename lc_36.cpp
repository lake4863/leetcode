class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check[3][9][9] = {false};
        
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if(c != '.') {
                    if(check[0][i][c - '1'] || check[1][j][c - '1'] || check[2][(j / 3) * 3 + (i / 3)][c - '1']) {
                        return false;
                    } else {
                        check[0][i][c - '1'] = true;
                        check[1][j][c - '1'] = true;
                        check[2][(j / 3) * 3 + (i / 3)][c - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};
