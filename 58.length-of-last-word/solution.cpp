class Solution {
public:
    int lengthOfLastWord(string s) {
        int last = s.length() - 1;
		for (int i = last; i >= 0; i--)
		{
			if (s[i] != ' ')
			{
				s.erase(i + 1, last - i);
				break;
			}
		}
		last = s.length() - 1;
        for (int i = 0; i <= last; i++)
            if (s[last - i] == ' ')
                return i;
        return s.length();
    }
};
