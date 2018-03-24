class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string ans = strs[0];
		for (vector<string>::iterator it = strs.begin() + 1; it != strs.end(); it++)
		{
			int len = it->length();
			int len2 = ans.length();
			if (len2 > len)
				ans = ans.substr(0, len);
			for (int i = 0; i < len; i++)
			{
				if ((*it)[i] != ans[i])
				{
					ans = ans.substr(0, i);
					break;
				}
			}
		}
		return ans;
    }
};
