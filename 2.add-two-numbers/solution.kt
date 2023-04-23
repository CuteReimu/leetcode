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
    fun addTwoNumbers(l1: ListNode?, l2: ListNode?): ListNode? {
        val root = ListNode(0)
        var c = 0
        var p1 = l1
        var p2 = l2
        var p = root
        while (p1 != null || p2 != null || c != 0) {
            val a = (p1?.`val` ?: 0) + (p2?.`val` ?: 0) + c
            c = a / 10
            p.next = ListNode(a % 10)
            p = p.next!!
            if (p1 != null) p1 = p1.next
            if (p2 != null) p2 = p2.next
        }
        return root.next
    }
}
