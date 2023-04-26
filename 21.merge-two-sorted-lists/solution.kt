/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
class Solution {
    fun mergeTwoLists(list1: ListNode?, list2: ListNode?): ListNode? {
        val root = ListNode(0)
        var p = root
        var p1 = list1
        var p2 = list2
        while (p1 != null || p2 != null) {
            if (p1 == null || p2 != null && p1.`val` > p2.`val`) {
                p.next = p2
                p2 = p2!!.next
            } else {
                p.next = p1
                p1 = p1.next
            }
            p.next!!.next = null
            p = p.next!!
        }
        return root.next
    }
}
