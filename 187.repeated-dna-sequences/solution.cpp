class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        unordered_map<string, int> cache;
        for (int i = 0; i <= (int)s.length() - 10; i++) {
            string s2 = s.substr(i, 10);
            if (++cache.emplace(s2, 0).first->second == 2) {
                result.push_back(s2);
            }
        }
        return result;
    }
};
