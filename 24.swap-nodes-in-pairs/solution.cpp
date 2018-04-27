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
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next)
		{
			return head;
		}
		ListNode *p = head->next;
		head->next = head->next->next;
		p->next = head;
		head = p;
		p = p->next;
		ListNode *pp = p->next;
		while (pp)
		{
			ListNode *q = pp->next;
			if (!q)
				break;
			pp->next = q->next;
			q->next = pp;
			p->next = q;
			p = pp;
			pp = p->next;
		}
		return head;
	}
};
