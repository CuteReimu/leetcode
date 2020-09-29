/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func diameterOfBinaryTree(root *TreeNode) int {
	return diameterOfBinaryTree2(root)[0]
}

func diameterOfBinaryTree2(root *TreeNode) []int {
	if root == nil {
		var ret = []int{0, 0}
		return ret
	}
	var left = diameterOfBinaryTree2(root.Left)
	var right = diameterOfBinaryTree2(root.Right)
	return []int{max(left[1]+right[1], max(left[0], right[0])), max(left[1], right[1]) + 1}
}

func max(a int, b int) int {
	if a < b {
		return b
	}
	return a
}
