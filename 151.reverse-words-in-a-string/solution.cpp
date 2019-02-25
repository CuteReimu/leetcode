class Solution {
public:
	void reverseWords(string &s) {
		int len = s.length();
		int j = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] != ' ' || i > 0 && s[i - 1] != ' ') {
				s[j++] = s[i];
			}
		}
		s.erase(j, s.length());
		if (s.empty()) return;
		if (s.back() != ' ') s += ' ';
		string::iterator it1 = s.begin(), it2 = s.begin();
		while (it2 != s.end()) {
			if (*it2 == ' ') {
				reverse(it1, it2);
				it1 = ++it2;
			} else
				++it2;
		}
		s.erase(s.length() - 1);
		reverse(s.begin(), s.end());
	}
};
