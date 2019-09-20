class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) return false;
        int i = matrix.length - 1, j = 0;
        int width = matrix[0].length;
        while (i >= 0 && j < width) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) j++;
            else i--;
        }
        return false;
    }
}
