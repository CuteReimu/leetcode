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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *newhead = new ListNode(0);
        for (ListNode *p = head; p != nullptr;) {
            ListNode *q;
            for (q = newhead; q->next != nullptr; q = q->next) {
                if (q->next->val > p->val) {
                    break;
                }
            }
            ListNode *tmp = p;
            p = p->next;
            tmp->next = q->next;
            q->next = tmp;
        }
        ListNode *tmp = newhead->next;
        delete newhead;
        return tmp;
    }
};
