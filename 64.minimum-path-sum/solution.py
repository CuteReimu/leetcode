class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        c = []
        for i in range(len(grid)):
            cc = []
            for j in range(len(grid[i])):
                cc.append(0)
            c.append(cc)
        c[0][0] = grid[0][0]
        for i in range(1, len(grid)):
            c[i][0] = grid[i][0] + c[i - 1][0]
        for j in range(1, len(grid[i])):
            c[0][j] = grid[0][j] + c[0][j - 1]
        for i in range(1, len(grid)):
            for j in range(1, len(grid[i])):
                c[i][j] = grid[i][j] + min(c[i - 1][j], c[i][j - 1])
        return c[len(c) - 1][len(c[0]) - 1]
