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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head)
		{
			return nullptr;
		}
		ListNode* lastNode = nullptr;
		ListNode* p = head;
		while (true)
		{
			if (!p) return head;
			ListNode* subHead = p;
			for (int i = 0; i < k - 1; i++)
			{
				p = p->next;
				if (!p) return head;
			}
			ListNode* tempNext = p->next;
			p->next = nullptr;
			ListNode* newEnd;
			if (!lastNode) head = swapAll(subHead, newEnd);
			else lastNode->next = swapAll(subHead, newEnd);
			lastNode = newEnd;
			p = newEnd->next = tempNext;
		}
		return head;
	}
private:
	ListNode* swapAll(ListNode* head, ListNode *&end)
	{
		if (!head) return end = nullptr;
		if (!head->next) return end = head;
		end = head;
		ListNode* oldSecond;
		ListNode* newHead = swapAll(head->next, oldSecond);
		oldSecond->next = end;
		end->next = nullptr;
		return newHead;
	}
};
