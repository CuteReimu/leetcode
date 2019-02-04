class Solution {
public:
	bool isScramble(string s1, string s2) {
		return isScramble(s1, 0, s1.length(), s2, 0, s2.length());
	}
private:
	bool isScramble(const string &s1, int beg1, int end1, const string &s2, int beg2, int end2)
	{
		int len = end1 - beg1;
		if (len != end2 - beg2)
			return false;
		if (len == 1)
			return s1[beg1] == s2[beg2];
		int count['z' + 1] = {0};
		for (int i = 0; i < len; i++)
		{
			count[s1[i + beg1]]++;
			count[s2[i + beg2]]--;
		}
		for (int i = 'A'; i <= 'z'; i++)
		{
			if (count[i])
			{
				return false;
			}
		}
		for (int i = 1; i < len; i++)
		{
			if (isScramble(s1, beg1, beg1 + i, s2, beg2, beg2 + i)
				&& isScramble(s1, beg1 + i, end1, s2, beg2 + i, end2)
				|| isScramble(s1, end1 - i, end1, s2, beg2, beg2 + i)
				&& isScramble(s1, beg1, end1 - i, s2, beg2 + i, end2))
			{
				return true;
			}
		}
		return false;
	}
};
