# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]):
        every = round(math.sqrt(len(lists)))
        listsn = []
        i = 0
        while True:
            if i + every >= len(lists):
                listsn.append(self.mergeKLists2(lists[i:]))
                break
            else:
                listsn.append(self.mergeKLists2(lists[i:i+every]))
            i += every
        return self.mergeKLists2(listsn)

    def mergeKLists2(self, lists: List[ListNode]) -> ListNode:
        head = ListNode(0)
        p = head
        while True:
            smallest = -1
            for i in range(len(lists)):
                if lists[i] is not None and (smallest == -1 or lists[i].val < lists[smallest].val):
                    smallest = i
            if smallest == -1:
                break
            p.next = lists[smallest]
            p = p.next
            lists[smallest] = lists[smallest].next
        return head.next
