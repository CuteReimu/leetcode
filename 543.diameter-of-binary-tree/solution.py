# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        return self.diameterOfBinaryTree2(root)[0]

    def diameterOfBinaryTree2(self, root: TreeNode) -> (int, int):
        if not root:
            return 0, 0
        leftdiameter, heightleft = self.diameterOfBinaryTree2(root.left);
        rightdiameter, heightright = self.diameterOfBinaryTree2(root.right);
        return max(heightleft + heightright, leftdiameter, rightdiameter), max(heightleft, heightright) + 1;
