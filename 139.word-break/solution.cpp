class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int len = s.length();
		set<int> cache;
		cache.insert(0);
		while (!cache.empty()) {
			const int &p = *cache.begin();
			for (string &ss : wordDict) {
				if (startWith(s, p, ss)) {
					if (p + ss.length() == len) return true;
					cache.insert(p + ss.length());
				}
			}
			cache.erase(cache.begin());
		}
		return false;
	}
private:
	bool startWith(const string &s, int start, const string &s1) {
		int len = s1.length();
		if (s.length() - start < len) return false;
		for (int i = 0; i < len; i++) {
			if (s[start + i] != s1[i]) return false;
		}
		return true;
	}
};
