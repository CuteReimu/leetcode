class Solution:
    def longestValidParentheses(self, s: str) -> int:
        cache = [0] * len(s)
        stack = []
        for i in range(len(s)):
            if s[i] == ')':
                if len(stack) == 0 or stack[-1][0] != '(':
                    cache[i] = 1
                else:
                    stack.pop()
            else:
                stack.append(('(', i))
        for s0 in stack:
            cache[s0[1]] = 1
        cur_len = 0
        max_len = 0
        for i in range(len(s)):
            if cache[i] == 1:
                max_len = max(max_len, cur_len)
                cur_len = 0
            else:
                cur_len += 1
        return max(max_len, cur_len)
