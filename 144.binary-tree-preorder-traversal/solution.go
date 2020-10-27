/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
	var result []int
	myList := list.New()
	myList.PushBack(root)
	for myList.Len() > 0 {
		p := myList.Back()
		value := myList.Remove(p)
		node := value.(*TreeNode)
		if node == nil {
			continue
		}
		result = append(result, node.Val)
		myList.PushBack(node.Right)
		myList.PushBack(node.Left)
	}
	return result
}
