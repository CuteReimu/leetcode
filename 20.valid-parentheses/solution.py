class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for i in s:
            if i == "}":
                if len(stack) == 0 or stack[-1] != "{":
                    return False
                stack.pop()
            elif i == "]":
                if len(stack) == 0 or stack[-1] != "[":
                    return False
                stack.pop()
            elif i == ")":
                if len(stack) == 0 or stack[-1] != "(":
                    return False
                stack.pop()
            else:
                stack.append(i)
        return len(stack) == 0
