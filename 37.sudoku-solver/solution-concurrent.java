import java.util.concurrent.*;

class Solution extends RecursiveTask<Boolean> {

    public void solveSudoku(char[][] board) {
        solveSudoku(board, 0);
    }

    private static void copy2DArray(char[][] src, char[][] dst) {
        for (int i = 0; i < src.length; i++)
            System.arraycopy(src[i], 0, dst[i], 0, src[i].length);
    }

    private char[][] board;
    private int index;
    public Solution() {}
    private Solution(char[][] board, int index) {
        this.board = new char[board.length][board[0].length];
        copy2DArray(board, this.board);
        this.index = index;
    }

    private boolean solveSudoku(char[][] board, int index) {
        if (index >= 81) return true;
        for (; index < 81; index++) {
            int i = index / 9;
            int j = index % 9;
            if (board[i][j] == '.') {
                List<Object[]> list = new ArrayList<>();
                for (char n = '1'; n <= '9'; n++) {
                    if (!check(board, i, j, n))
                        continue;
                    board[i][j] = n;
                    Solution s = new Solution(board, index + 1);
                    ForkJoinTask<Boolean> task = s.fork();
                    list.add(new Object[]{task, s});
                }
                boolean ret = false;
                for (Object[] arr : list) {
                    ForkJoinTask<Boolean> task = (ForkJoinTask<Boolean>) arr[0];
                    boolean val = task.join();
                    if (ret) continue;
                    if (!val) continue;
                    Solution s = (Solution) arr[1];
                    copy2DArray(s.board, board);
                    ret = true;
                }
                if (ret) return true;
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

    @Override
    protected Boolean compute() {
        return solveSudoku(board, index);
    }
}
