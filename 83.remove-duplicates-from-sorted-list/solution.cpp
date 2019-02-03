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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *p = head;
		ListNode *q;
		int t;
		while (p)
		{
			if (p->val == t && p != head)
			{
				q->next = p->next;
				p = q->next;
				continue;
			}
			t = p->val;
			q = p;
			p = p->next;
		}
		return head;
	}
};
