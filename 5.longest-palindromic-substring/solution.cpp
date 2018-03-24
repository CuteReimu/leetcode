class Solution {
public:
    string longestPalindrome(string s) {
		string ss("#");
		int len = s.length();
		for (int i = 0; i < len; i++)
		{
			ss += s[i];
			ss += '#';
		}
		int maxLen = 1;
		len = ss.length();
		int maxCenter = 1;
		for (int center = 2; center + maxLen < len; center++)
		{
			int j = 1;
			for (; center - j >= 0 && center + j < len; j++)
				if (ss[center - j] != ss[center + j])
					break;
			j--;
			if (j > maxLen)
			{
				maxLen = j;
				maxCenter = center;
			}
		}
		string maxAns = ss.substr(maxCenter - maxLen, 2 * maxLen + 1);
		len = maxAns.length() / 2;
		string ans;
		for (int i = 0; i < len; i++)
			ans += maxAns[i * 2 + 1];
		return ans;
    }
};
