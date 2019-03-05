class Trie {
private:
    struct TreeNode {
        TreeNode *children[27];
        TreeNode () {
            memset(children, 0, sizeof(children));
        }
    };
public:
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode *p = &head;
        for (int i = 0; i < word.length(); i++) {
            if (nullptr == p->children[word[i] - 'a'])
                p->children[word[i] - 'a'] = new TreeNode();
            p = p->children[word[i] - 'a'];
        }
        p->children[26] = &end;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TreeNode *p = &head;
        for (int i = 0; i < word.length(); i++) {
            if (nullptr == p->children[word[i] - 'a'])
                return false;
            p = p->children[word[i] - 'a'];
        }
        return p->children[26] != nullptr;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode *p = &head;
        for (int i = 0; i < prefix.length(); i++) {
            if (nullptr == p->children[prefix[i] - 'a'])
                return false;
            p = p->children[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TreeNode head;
    TreeNode end;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
