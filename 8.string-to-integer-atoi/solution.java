class Solution {
    public int myAtoi(String str) {
		int i = -1;
		int len = str.length();
		while (true){
			++i;
			if (i >= len)
				return 0;
			if (str.charAt(i) != ' ')
				break;
		}
		int sign = 1;
		if (str.charAt(i) == '-') {
			sign = -1;
			i++;
		} else if (str.charAt(i) == '+')
			i++;
		long ans = 0;
		while (i < len)
		{
			char ch = str.charAt(i);
			if (ch < '0' || ch > '9')
				break;
			ans = ans * 10 + (ch - '0');
			if (sign == 1 && ans > Integer.MAX_VALUE)
				return Integer.MAX_VALUE;
			if (sign == -1 && ans - 1 > Integer.MAX_VALUE)
				return Integer.MIN_VALUE;
			i++;
		}
		return (int) (sign * ans);
    }
}
