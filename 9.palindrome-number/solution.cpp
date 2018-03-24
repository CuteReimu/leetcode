class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0)
			return false;
		char s[15];
		sprintf(s, "%d", x);
		int len = strlen(s);
		int half = len / 2;
		for (int i = 0; i < half; i++)
		{
			if (s[i] != s[len - 1 - i])
				return false;
		}
		return true;
    }
};
