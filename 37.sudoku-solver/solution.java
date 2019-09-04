class Solution {
    public void solveSudoku(char[][] board) {
        solveSudoku(board, 0);
    }
    private boolean solveSudoku(char[][] board, int index) {
        if (index >= 81) return true;
        for (; index < 81; index++) {
            int i = index / 9;
            int j = index % 9;
            if (board[i][j] == '.') {
                for (char n = '1'; n <= '9'; n++) {
                    if (!check(board, i, j, n))
                        continue;
                    board[i][j] = n;
                    if (solveSudoku(board, index + 1))
                        return true;
                }
                board[i][j] = '.';
                return false;
            }
        }
        return true;
    }
    private boolean check(char[][] board, int i, int j, char n) {
        for (int x = 0; x < 9; x++) {
            if (board[x][j] == n || board[i][x] == n)
                return false;
        }
        i = i / 3 * 3;
        j = j / 3 * 3;
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[i + x][j + y] == n)
                    return false;
            }
        }
        return true;
    }
}
