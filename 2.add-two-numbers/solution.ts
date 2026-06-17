/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const p = new ListNode();
    let q = p;
    let c = 0, sum = 0;
    while (l1 || l2 || c) {
        sum = (l1?.val ?? 0) + (l2?.val ?? 0) + c;
        q.next = new ListNode(sum % 10);
        q = q.next;
        c = (sum - q.val) / 10;
        l1 = l1?.next;
        l2 = l2?.next;
    }
    return p.next;
};
