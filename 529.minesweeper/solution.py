class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        queue = set()
        queue.add((click[0], click[1]))
        while len(queue) > 0:
            cur = queue.pop()
            if board[cur[0]][cur[1]] == 'M':
                board[cur[0]][cur[1]] = 'X'
                break
            near = 0
            for i in range(cur[0] - 1, cur[0] + 2):
                for j in range(cur[1] - 1, cur[1] + 2):
                    if 0 <= i < len(board) and 0 <= j < len(board[0]) and board[i][j] == 'M':
                        near += 1
            if near > 0:
                board[cur[0]][cur[1]] = str(near)
                continue
            board[cur[0]][cur[1]] = 'B'
            for i in range(cur[0] - 1, cur[0] + 2):
                for j in range(cur[1] - 1, cur[1] + 2):
                    if 0 <= i < len(board) and 0 <= j < len(board[0]) and board[i][j] == 'E':
                        queue.add((i, j))
        return board
