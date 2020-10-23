/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	var temp []int
	for ; head != nil; head = head.Next {
		temp = append(temp, head.Val)
	}
	for i, val := range temp[0 : len(temp)/2] {
		if val != temp[len(temp)-1-i] {
			return false
		}
	}
	return true
}
