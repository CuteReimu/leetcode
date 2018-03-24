class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int position[256] = {0};
		int p = 0, q = 0;
		int len = 0;
		while (q < s.length())
		{
			char c = s[q];
			if (position[c] != 0)
			{
				len = max(len, q - p);
				p = position[c];
				q = p;
				memset(position, 0, 256 * sizeof(int));
			} else
			{
				position[c] = ++q;
			}
		}
		return max(len, q - p);
    }
};
