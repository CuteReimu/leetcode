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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		multimap<int, ListNode*> temp;
		for (auto it = lists.begin(); it != lists.end(); it++)
			for (ListNode *p = *it; p; p = p->next)
				temp.emplace(p->val, p);
		ListNode* head = nullptr;
		ListNode* p = nullptr;
		for (auto it = temp.begin(); it != temp.end(); it++)
		{
			if (p) p = p->next = it->second;
			else head = p = it->second;
		}
		if (p) p->next = nullptr;
		return head;
    }
};
