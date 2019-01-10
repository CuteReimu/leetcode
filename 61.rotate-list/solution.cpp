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
    ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return nullptr;
        int len = 0;
		ListNode* tail = nullptr;
		for (ListNode* p = head; p != nullptr; p = p->next)
		{
			len++;
			if (!p->next) tail = p;
		}
		k %= len;
		if (!k) return head;
		tail->next = head;
		ListNode* p = head;
		for (int i = k + 1; i < len; i++)
			p = p->next;
		head = p->next;
		p->next = nullptr;
		return head;
    }
};
