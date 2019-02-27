class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> cache1;
        unordered_set<char> cache2;
        int len = s.size();
        for (int i = 0; i < len; i++) {
            auto result = cache1.emplace(s[i], t[i]);
            if (result.second) {
                if (!cache2.insert(t[i]).second) return false;
            } else {
                if (result.first->second != t[i]) return false;
            }
        }
        return true;
    }
};
