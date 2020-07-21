# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def generateTrees(self, n):
        if n == 0:
            return []
        return self.gt(n, 1)
        """
        :type n: int
        :rtype: List[TreeNode]
        """

    def gt(self, n, start):
        if n == 0:
            return [None]
        if n == 1:
            return [TreeNode(start)]
        result = []
        for i in range(start, start + n):
            list1 = self.gt(i - start, start)
            list2 = self.gt(n - i + start - 1, i + 1)
            for x in list1:
                for y in list2:
                    result.append(TreeNode(i, x, y))
        return result
