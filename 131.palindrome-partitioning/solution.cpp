class Solution {
private:
    map<pair<int, int>, vector<vector<string>>> cache;
    void partition(const string &s, int beg, int end) {
        if (end - beg <= 0) return;
        pair<int, int> p(beg, end);
        auto it = cache.find(p);
        if (it != cache.end()) return;
        vector<vector<string>> &result = cache[p];
        for (int i = beg + 1; i < end; i++) {
            int mid = (i + end) / 2;
            bool isNotOk = false;
            for (int j = i; j < mid; j++) {
                if (s[j] != s[i + end - j - 1]) {
                    isNotOk = true;
                    break;
                }
            }
            if (isNotOk) continue;
            partition(s, beg, i);
            vector<vector<string>> &result1 = cache[make_pair(beg, i)];
            for (vector<string> &vec1 : result1) {
                result.emplace_back(vec1.begin(), vec1.end());
                result.back().push_back(s.substr(i, end - i));
            }
        }
        int mid = (beg + end) / 2;
        for (int j = beg; j < mid; j++) {
            if (s[j] != s[beg + end - j - 1]) {
                return;
            }
        }
        result.emplace_back(1, s.substr(beg, end - beg));
    }
public:
    vector<vector<string>> partition(string s) {
        cache.clear();
        partition(s, 0, s.length());
        return cache[make_pair(0, s.length())];
    }
};
