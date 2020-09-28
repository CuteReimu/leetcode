/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *first = nullptr;
        Node *p = root;
        Node *q = nullptr;
        while (p) {
            if (p->left) {
                if (q) q = q->next = p->left;
                else q = p->left;
                if (!first) first = p->left;
            }
            if (p->right) {
                if (q) q = q->next = p->right;
                else q = p->right;
                if (!first) first = p->right;
            }
            p = p->next;
            if (!p) {
                p = first;
                q = nullptr;
                first = nullptr;
            }
        }
        return root;
    }
};
