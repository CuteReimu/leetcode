class Solution {
private:
    int h;
    int w;
    void solve(vector<vector<char>>& board, int i, int j) {
        if (i > 0 && board[i - 1][j] == 'O') {
            board[i - 1][j] = '-';
            solve(board, i - 1, j);
        }
        if (i < h - 1 && board[i + 1][j] == 'O') {
            board[i + 1][j] = '-';
            solve(board, i + 1, j);
        }
        if (j > 0 && board[i][j - 1] == 'O') {
            board[i][j - 1] = '-';
            solve(board, i, j - 1);
        }
        if (j < w - 1 && board[i][j + 1] == 'O') {
            board[i][j + 1] = '-';
            solve(board, i, j + 1);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        h = board.size();
        if (h <= 2) return;
        w = board.front().size();
        if (w <= 2) return;
        for (int i = 1; i < w; i++) {
            if (board[0][i - 1] == 'O') {
                board[0][i - 1] = '-';
                solve(board, 0, i - 1);
            }
            if (board[h - 1][i] == 'O') {
                board[h - 1][i] = '-';
                solve(board, h - 1, i);
            }
        }
        for (int i = 1; i < h; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = '-';
                solve(board, i, 0);
            }
            if (board[i - 1][w - 1] == 'O') {
                board[i - 1][w - 1] = '-';
                solve(board, i - 1, w - 1);
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '-') board[i][j] = 'O';
            }
        }
    }
};
