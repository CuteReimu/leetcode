/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		ListNode head2(0);
		head2.next = head;
		ListNode *p1 = &head2;
		for (int i = 1; i < m; i++)
			p1 = p1->next;
		ListNode *head1 = p1->next;
		ListNode *&tail1 = head1->next;
		for (int i = m; i < n; i++)
		{
			ListNode *p = tail1;
			tail1 = p->next;
			p->next = head1;
			head1 = p;
		}
		p1->next = head1;
		return head2.next;
	}
};
