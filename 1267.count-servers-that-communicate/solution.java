class Solution {
    public int countServers(int[][] grid) {
        int[] iArr = new int[grid.length];
        int[] jArr = new int[grid[0].length];
        for (int i = 0; i < iArr.length; i++) {
            for (int j = 0; j < jArr.length; j++) {
                if (grid[i][j] == 1) {
                    iArr[i]++;
                    jArr[j]++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1 && (iArr[i] > 1 || jArr[j] > 1))
                    count++;
            }
        }
        return count;
    }
}
