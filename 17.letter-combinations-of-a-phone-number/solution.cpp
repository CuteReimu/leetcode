class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.empty())
			return result;
		string s;
		foreachLetter(digits.c_str(), s, result);
		return result;
	}

	void foreachLetter(const char *digits, string &s, vector<string> &result) {
		static const string IARR[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		if (*digits == '\0')
		{
			result.push_back(s);
			return;
		}
		int val = *digits - '0';
		const string &chs = IARR[val];
		for (unsigned int i = 0; i < chs.length(); i++)
		{
			s += chs[i];
			foreachLetter(digits + 1, s, result);
			s.erase(s.size() - 1);
		}
	}
};
