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
    void reorderList(ListNode* head) {
        if (nullptr == head) return;
        vector<ListNode *> vec;
        ListNode *p = head;
        while (p) {
            vec.push_back(p);
            p = p->next;
        }
        int len = vec.size();
        if (len % 2 == 0) {
            head->next = vec[len - 1];
            p = head->next;
            for (int i = 1; i < len / 2; i++) {
                p = p->next = vec[i];
                p = p->next = vec[len - 1 - i];
            }
        } else {
            p = head;
            len++;
            for (int i = 1; i < len / 2; i++) {
                p = p->next = vec[len - 1 - i];
                p = p->next = vec[i];
            }
        }
        p->next = nullptr;
    }
};
