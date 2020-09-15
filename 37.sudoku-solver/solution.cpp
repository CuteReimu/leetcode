class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board, 0);
    }
private:
    bool solveSudoku(vector<vector<char>>& board, int pos) {
        int i, j;
        do {
            if (pos >= 9 * 9)
                return true;
            i = pos / 9;
            j = pos % 9;
            if (board[i][j] == '.')
                break;
            pos++;
        } while (true);
        for (int v = 1; v <= 9; v++) {
            if (check(board, i, j, '0' + v)) {
                board[i][j] = '0' + v;
                if (solveSudoku(board, pos + 1)) {
                    return true;
                }
            }
        }
        board[i][j] = '.';
        return false;
    }

    bool check(vector<vector<char>>& board, int i, int j, char v) {
        for (int x = 0; x < 9; x++) {
            if (board[i][x] == v)
                return false;
            if (board[x][j] == v)
                return false;
            if (board[i / 3 * 3 + x / 3][j / 3 * 3 + x % 3] == v)
                return false;
        }
        return true;
    }
};
