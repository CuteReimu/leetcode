/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
	var cache []int
	return preorderTraversal2(root, cache)
}

func preorderTraversal2(root *TreeNode, cache []int) []int {
	if root == nil {
		return cache
	}
	cache = append(cache, root.Val)
	cache = preorderTraversal2(root.Left, cache)
	return preorderTraversal2(root.Right, cache)
}
