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
		ListNode *head1 = head;
        ListNode *p = head;
        ListNode *q = nullptr, *p1 = nullptr;
        int t = 0;
        while (p)
        {
            if (p->val == t && p != head1)
            {
                if (p1)
					p1->next = p->next;
				else
					head = p->next;
				q = p1;
                p = p->next;
                continue;
            }
            t = p->val;
            p1 = q;
            q = p;
            p = p->next;
        }
        return head;
    }
};