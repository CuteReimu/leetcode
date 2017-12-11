/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	ListNode ans = new ListNode(0);
    	ListNode p1 = l1;
    	ListNode p2 = l2;
    	ListNode pAns = ans;
    	int carry = 0;
    	while (true)
    	{
    		if (p1 != null)
    		{
    			pAns.val += p1.val;
    			p1 = p1.next;
    		}
    		if (p2 != null)
    		{
    			pAns.val += p2.val;
    			p2 = p2.next;
    		}
			pAns.val += carry;
			carry = pAns.val / 10;
			pAns.val %= 10;
    		if (p1 == null && p2 == null && carry == 0)
    			break;
    		pAns.next = new ListNode(0);
    		pAns = pAns.next;
    	}
    	return ans;
    }
}
