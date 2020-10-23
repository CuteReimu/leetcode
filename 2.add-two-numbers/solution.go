/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var sum int
	var head ListNode
	l3 := &head
	for l1 != nil || l2 != nil {
		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}
		l3.Next = new(ListNode)
		l3 = l3.Next
		l3.Val = sum % 10
		sum /= 10
	}
	if sum != 0 {
		l3.Next = new(ListNode)
		l3 = l3.Next
		l3.Val = sum % 10
	}
	return head.Next
}
