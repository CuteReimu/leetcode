class StreamChecker {
    struct TreeNode {
        char val;
        TreeNode *next[27];
        TreeNode(char val):val(val) {
			memset(next, 0, 27 * sizeof(TreeNode *));
        }
    };
public:
    StreamChecker(vector<string>& words) {
        head = new TreeNode('\0');
        for (const string &s : words) {
            TreeNode *p = head;
            for (char c : s) {
                if (p->next[c - 'a' + 1] == nullptr) {
                    p->next[c - 'a' + 1] = new TreeNode(c);
                }
                p = p->next[c - 'a' + 1];
            }
            if (p->next[0] == nullptr) {
                p->next[0] = new TreeNode('\0');
            }
        }
    }

    bool query(char letter) {
        bool found = false;
        for (auto it = vec.begin(); it != vec.end(); ) {
            TreeNode *p = *it;
            if (p->next[letter - 'a' + 1] == nullptr) {
                it = vec.erase(it);
                continue;
            }
            *it = p = p->next[letter - 'a' + 1];
            if (p->next[0] != nullptr) {
                found = true;
            }
            it++;
        }
        TreeNode *p = head->next[letter - 'a' + 1];
        if (p != nullptr) {
            vec.push_back(p);
            if (p->next[0] != nullptr) {
                found = true;
            }
        }
        return found;
    }
private:
    TreeNode *head;
    vector<TreeNode *> vec;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
