/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        unordered_map<RandomListNode *, RandomListNode *> cache;
        RandomListNode *newHead = new RandomListNode(0);
        RandomListNode *p = head, *q = newHead;
        while (p) {
            q->next = new RandomListNode(p->label);
            q = q->next;
            cache.emplace(p, q);
            p = p->next;
        }
        p = head;
        q = newHead->next;
        while (p) {
            if (p->random) q->random = cache[p->random];
            q = q->next;
            p = p->next;
		}
		q = newHead->next;
		delete newHead;
        return q;
    }
};
