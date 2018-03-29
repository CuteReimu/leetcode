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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode *head = l1->val <= l2->val ? l1 : l2;
		ListNode *p = head;
		while (l1 != NULL || l2 != NULL)
		{
			ListNode *tmp;
			if (l1 == NULL || (l2 != NULL && l1->val > l2->val))
			{
				tmp = l2;
				l2 = l2->next;
			} else
			{
				tmp = l1;
				l1 = l1->next;
			}
			p->next = tmp;
			p = p->next;
		}
		return head;
	}
};
