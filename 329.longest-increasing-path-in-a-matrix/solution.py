class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if len(matrix) == 0:
            return 0
        cache = [[0 for x in range(len(matrix[0]))] for x in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                self.dp(matrix, cache, i, j)
        return max(max(x) for x in cache)

    def dp(self, matrix: List[List[int]], cache: List[List[int]], x: int, y: int) -> int:
        if cache[x][y] != 0:
            return cache[x][y]
        val = matrix[x][y]
        result = 1
        if x - 1 >= 0 and matrix[x - 1][y] > val:
            result = max(result, self.dp(matrix, cache, x - 1, y) + 1)
        if x + 1 < len(matrix) and matrix[x + 1][y] > val:
            result = max(result, self.dp(matrix, cache, x + 1, y) + 1)
        if y - 1 >= 0 and matrix[x][y - 1] > val:
            result = max(result, self.dp(matrix, cache, x, y - 1) + 1)
        if y + 1 < len(matrix[x]) and matrix[x][y + 1] > val:
            result = max(result, self.dp(matrix, cache, x, y + 1) + 1)
        cache[x][y] = result
        return result
