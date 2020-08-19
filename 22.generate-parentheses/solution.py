class Solution:
    def __init__(self):
        self.result = []

    def generateParenthesis(self, n: int) -> List[str]:
        self.result = []
        self.generateParenthesis2(n, 0, 0, "")
        return self.result

    def generateParenthesis2(self, n: int, left: int, right: int, cur: str):
        if left == n and right == n:
            self.result.append(cur)
        if left < n:
            self.generateParenthesis2(n, left+1, right, cur+"(")
        if left > right:
            self.generateParenthesis2(n, left, right+1, cur+")")
