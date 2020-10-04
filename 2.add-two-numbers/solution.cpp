/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }

private:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
        if (l1) {
            if (l2) {
                int val = l1->val + l2->val + carry;
                return new ListNode(val % 10, addTwoNumbers(l1->next, l2->next, val / 10));
            } else {
                int val = l1->val + carry;
                return new ListNode(val % 10, addTwoNumbers(l1->next, nullptr, val / 10));
            }
        } else {
            if (l2) {
                int val = l2->val + carry;
                return new ListNode(val % 10, addTwoNumbers(nullptr, l2->next, val / 10));
            } else {
                return carry > 0 ? new ListNode(carry) : nullptr;
            }
        }
    }
};
