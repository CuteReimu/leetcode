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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *pA = headA, *pB = headB;
        int diff = 0;
        while (pA->next) {
            pA = pA->next;
            diff++;
        }
        while (pB->next) {
            pB = pB->next;
            diff--;
        }
        if (pA != pB) return nullptr;
        pA = headB, pB = headA;
        while (diff > 0) {
            pB = pB->next;
            diff--;
        }
        while (diff < 0) {
            pA = pA->next;
            diff++;
        }
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};
