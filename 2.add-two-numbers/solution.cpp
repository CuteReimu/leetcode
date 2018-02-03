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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        clear(ans);
        int carry = 0;
        ListNode *head = NULL, *p = NULL;
        while (l1 != NULL && l2 != NULL)
        {
            if (p == NULL)
            {
                head = new ListNode(l1->val + l2->val);
                p = head;
            } else
            {
                p->next = new ListNode(carry + l1->val + l2->val);
                p = p->next;
            }
            carry = p->val / 10;
            p->val %= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != NULL || l2 != NULL)
        {
            ListNode *q = l1 != NULL ? l1 : l2;
            while (q != NULL)
            {
                p -> next = new ListNode(carry + q->val);
                p = p->next;
                q = q->next;
                carry = p->val / 10;
                p->val %= 10;
            }
        }
        if (carry > 0)
        {
            p->next = new ListNode(carry);
        }
        return head;
    }
    virtual ~Solution()
    {
        clear(ans);
    }
private:
    ListNode* ans;
    static void clear(ListNode *ans)
    {
        if (ans != NULL)
        {
            clear(ans->next);
            delete ans;
        }
    }
};
