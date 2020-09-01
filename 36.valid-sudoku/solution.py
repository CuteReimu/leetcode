class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(9):
            s1 = set()
            s2 = set()
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in s1:
                        return False
                    s1.add(board[i][j])
                if board[j][i] != '.':
                    if board[j][i] in s2:
                        return False
                    s2.add(board[j][i])
        for ii in range(0, 9, 3):
            for jj in range(0, 9, 3):
                s = set()
                for i in range(ii, ii+3):
                    for j in range(jj, jj+3):
                        if board[i][j] != '.':
                            if board[i][j] in s:
                                return False
                            s.add(board[i][j])
        return True
