class Solution {
public:
	int longestValidParentheses(string s) {
		bool mod = true;
		while (mod)
		{
			mod = false;
			int pleft;
			for (int i = 0; i < s.length();)
			{
				if (s[i] == '(')
				{
					pleft = i++;
					if (i < s.length())
					{
						while (s[i] == '@') i++;
						if (s[i] == ')')
						{
							s[pleft] = '@';
							s[i] = '@';
							mod = true;
						} else
							continue;
					}
				}
				i++;
			}
		}
		int maxlen = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '@')
			{
				int len = 0;
				for (; i < s.length(); i++)
				{
					if (s[i] != '@')
						break;
					len++;
				}
				maxlen = max(maxlen, len);
			}
		}
		return maxlen;
	}
};
