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
    ListNode* partition(ListNode* head, int x) {
        ListNode *p = head, *q = nullptr, *head2 = nullptr, *q2 = nullptr;
		while (p)
		{
			if (p->val >= x)
			{
				if (!head2)
					q2 = head2 = p;
				else
					q2 = q2->next = p;
				if (q)
				{
					q->next = p->next;
					p = q->next;
				} else
				{
					p = head = p->next;
				}
				q2->next = nullptr;
			} else
			{
				q = p;
				p = q->next;
			}
		}
		if (head2)
		{
			if (q)
				q->next = head2;
			else
				head = head2;
		}
		return head;
    }
};
