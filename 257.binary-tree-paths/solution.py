# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if root is None:
            return []
        if root.left is None and root.right is None:
            return [str(root.val)]
        result = []
        if root.left is not None:
            result0 = self.binaryTreePaths(root.left)
            for s in result0:
                result.append(str(root.val) + '->' + s)
        if root.right is not None:
            result0 = self.binaryTreePaths(root.right)
            for s in result0:
                result.append(str(root.val) + '->' + s)
        return result
