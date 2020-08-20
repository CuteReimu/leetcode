# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        p = ListNode(0)
        p.next = head
        head = p
        while p.next is not None and p.next.next is not None:
            tmp = p.next
            p.next = tmp.next
            tmp.next = p.next.next
            p.next.next = tmp
            p = p.next.next
        return head.next
