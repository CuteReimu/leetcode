class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> vec;
        for (const string &query : queries) {
            vec.push_back(camelMatch(query, pattern));
        }
        return vec;
    }
private:
    bool camelMatch(const string &s, const string &pattern) {
        if (s.length() < pattern.length())
            return false;
        if (s.length() == pattern.length())
            return s == pattern;
        int i = 0, j = 0;
        while (true) {
            if (i == s.length())
                return j == pattern.length();
            if (j < pattern.length() && s[i] == pattern[j]) {
                i++;
                j++;
                continue;
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                return false;
            }
            i++;
        }
    }
};
