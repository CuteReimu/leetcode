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
        Node *nextLine = nullptr;
        Node *p = root;
        Node *lastNode = nullptr;
        while (p)
        {
            if (!nextLine) nextLine = p->left;
            if (!nextLine) nextLine = p->right;
            if (p->left && p->right)
            {
                p->left->next = p->right;
                if (lastNode) lastNode->next = p->left;
                lastNode = p->right;
            }
            else if (p->left)
            {
                if (lastNode) lastNode->next = p->left;
                lastNode = p->left;
            }
            else if (p->right)
            {
                if (lastNode) lastNode->next = p->right;
                lastNode = p->right;
            }
            if (p->next)
            {
                p = p->next;
            }
            else
            {
                p = nextLine;
                nextLine = nullptr;
                lastNode = nullptr;
            }
        }
        return root;
    }
};
