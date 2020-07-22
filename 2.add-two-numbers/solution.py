# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        p1 = l1
        p2 = l2
        head = None
        p = head
        c = 0
        while p1 is not None or p2 is not None or c != 0:
            if head is None:
                p = head = ListNode(0)
            else:
                p.next = ListNode(0)
                p = p.next
            if p1 is not None:
                p.val += p1.val
            if p2 is not None:
                p.val += p2.val
            p.val += c
            if p.val >= 10:
                p.val -= 10
                c = 1
            else:
                c = 0
            if p1 is not None:
                p1 = p1.next
            if p2 is not None:
                p2 = p2.next
        return head
