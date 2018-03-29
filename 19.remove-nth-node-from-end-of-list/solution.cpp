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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode *> vec;
		ListNode *p = head;
		while (p != NULL)
		{
			vec.push_back(p);
			p = p->next;
		}
		ListNode *pl = vec[vec.size() - n];
		if (pl == head)
			return pl->next;
		vec[vec.size() - n - 1]->next = pl->next;
		return head;
    }
};
