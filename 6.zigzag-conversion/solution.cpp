class Solution {
public:
    string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int len = s.length();
		string ans;
		for (int i = 0; i < numRows; i++)
		{
			if (i >= len)
				break;
			ans += s[i];
			for (int j = 1;; j++)
			{
				if (i != 0 && i != numRows - 1)
				{
					int index = j * (numRows - 1) * 2 - i;
					if (index >= len)
						break;
					ans += s[index];
				}
				int index = i + j * (numRows - 1) * 2;
				if (index >= len)
					break;
				ans += s[index];
			}
		}
		return ans;
    }
};
