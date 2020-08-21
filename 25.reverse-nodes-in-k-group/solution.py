# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        p = head
        head = ListNode(0)
        head.next = p
        p = head
        while True:
            q = p
            for i in range(k):
                if p.next is None:
                    return head.next
                p = p.next
            new_head, new_tail = self.reverseJustKGroup(q.next, k)
            q.next = new_head
            p = new_tail

    def reverseJustKGroup(self, head: ListNode, k: int) -> (ListNode, ListNode):
        if k == 1:
            return head, head
        new_head, new_tail = self.reverseJustKGroup(head.next, k - 1)
        head.next = new_tail.next
        new_tail.next = head
        return new_head, new_tail.next
