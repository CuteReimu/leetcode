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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> cache;
        while (head) {
            auto result = cache.insert(head);
            if (!result.second) return *result.first;
            head = head->next;
        }
        return nullptr;
    }
};
