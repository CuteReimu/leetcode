class Solution {
public:
    int myAtoi(const string &str) {
		int i = -1;
		int len = str.length();
		while (true){
			++i;
			if (i >= len)
				return 0;
			if (str[i] != ' ')
				break;
		}
		int sign = 1;
		if (str[i] == '-') {
			sign = -1;
			i++;
		} else if (str[i] == '+')
			i++;
		long ans = 0;
		while (i < len)
		{
			char ch = str[i];
			if (ch < '0' || ch > '9')
				break;
			ans = ans * 10 + (ch - '0');
			if (sign == 1 && ans > INT_MAX)
				return INT_MAX;
			if (sign == -1 && ans - 1 > INT_MAX)
				return INT_MIN;
			i++;
		}
		return (int) (sign * ans);
    }
};