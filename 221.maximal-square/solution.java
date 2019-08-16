class Solution {
    public int maximalSquare(char[][] matrix) {
        int max = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                for (int k = 0; i + k < matrix.length && j + k < matrix[i].length; k++) {
                    int size = (k + 1) * (k + 1);
                    if (size > max) {
                        if (check(matrix, i, j, i + k, j + k)) {
                            max = size;
                        }
                    }
                }
            }
        }
        return max;
    }

    private boolean check(char[][] matrix, int i, int j, int ii, int jj) {
        for (int x = i; x <= ii; x++) {
            for (int y = j; y <= jj; y++) {
                if (matrix[x][y] == '0') {
                    return false;
                }
            }
        }
        return true;
    }
}
