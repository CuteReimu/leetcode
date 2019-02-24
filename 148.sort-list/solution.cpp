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
	ListNode* sortList(ListNode* head) {
		return sortList(head, nullptr);
	}
private:
	ListNode *sortList(ListNode* begin, ListNode* end) {
		if (!begin) return nullptr;
		if (begin == end || begin->next == end) return begin;
		ListNode* pHead = begin, *pTail = begin, *pMid = begin;
		int val = begin->val;
		begin = begin->next;
		pTail->next = nullptr;
		while (begin != end) {
			if (begin->val <= val) {
				ListNode *tmp = begin;
				begin = begin->next;
				tmp->next = pHead;
				pHead = tmp;
			} else
			{
				pTail->next = begin;
				pTail = pTail->next;
				begin = begin->next;
				pTail->next = nullptr;
			}
		}
		pTail->next = end;
		pHead = sortList(pHead, pMid);
		pMid->next = sortList(pMid->next, end);
		return pHead;
	}
};
