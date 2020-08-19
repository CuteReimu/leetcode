# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        newHead = ListNode(0)
        newHead.next = head
        self.doRemove(newHead, n)
        return newHead.next

    def doRemove(self, cur: ListNode, n: int) -> int:
        if cur is None:
            return 0
        curN = self.doRemove(cur.next, n)
        if curN == n:
            cur.next = cur.next.next
        return curN + 1
