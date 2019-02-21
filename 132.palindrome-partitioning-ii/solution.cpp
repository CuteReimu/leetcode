class Solution {
private:
    bool isOk(const string &s, int start, int len) {
        for (int i = 0; i < len / 2; i++) {
            if (s[start + i] != s[start + len - 1 - i]) return false;
        }
        return true;
    }
public:
    int minCut(string s) {
        int len = s.length();
        if (isOk(s, 0, len)) return 0;
        for (int i = 1; i < len; i++) {
            if (isOk(s, 0, i) && isOk(s, i, len - i)) return 1;
        }
        vector<vector<int>> vec(len);
        for (int i = 0; i < len; i++) {
            for (int j = 0; 0 <= i - j && i + j < len; j++) {
                if (s[i - j] != s[i + j]) break;
                vec[i - j].push_back(j * 2 + 1);
            }
            for (int j = 1; 0 <= i - j + 1 && i + j < len; j++) {
                if (s[i - j + 1] != s[i + j]) break;
                vec[i - j + 1].push_back(j * 2);
            }
        }
        set<pair<int, int>> cache;
        cache.emplace(0, 0);
        while (!cache.empty()) {
            set<pair<int, int>>::iterator it = cache.begin();
            pair<int, int> p = *it;
            cache.erase(it);
            for (int &i : vec[p.second]) {
                if (p.second + i == len) return p.first;
                cache.emplace(p.first + 1, p.second + i);
            }
        }
        return -1;
    }
};
