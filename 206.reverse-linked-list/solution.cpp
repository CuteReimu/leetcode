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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        stack<ListNode *> cache;
        for (; head; head = head->next) {
            cache.push(head);
        }
        ListNode *p = head = cache.top();
        cache.pop();
        while (!cache.empty()) {
            p = p->next = cache.top();
            cache.pop();
        }
        p->next = nullptr;
        return head;
    }
};
