class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (!wordBreak1(s, wordDict)) return vector<string>();
		int len = s.length();
		map<int, vector<string>> cache;
		cache.emplace(0, vector<string>(1));
		while (!cache.empty()) {
			pair<const int, vector<string>> &p = *cache.begin();
			if (p.first == len) break;
			for (string &ss : wordDict) {
				if (startWith(s, p.first, ss)) {
					for (string &result1 : p.second) {
						vector<string> &vec = cache[p.first + ss.length()];
						vec.push_back(result1);
						if (!result1.empty())
							vec.back().append(1, ' ');
						vec.back() += ss;
					}
				}
			}
			cache.erase(cache.begin());
		}
		vector<string> result;
		for (pair<const int, vector<string>> &p : cache) {
			result.insert(result.end(), p.second.begin(), p.second.end());
		}
		return result;
	}
private:
	bool wordBreak1(const string &s, vector<string>& wordDict) {
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
	bool startWith(const string &s, int start, const string &s1) {
		int len = s1.length();
		if (s.length() - start < len) return false;
		for (int i = 0; i < len; i++) {
			if (s[start + i] != s1[i]) return false;
		}
		return true;
	}
};
