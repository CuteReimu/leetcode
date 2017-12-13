class Solution {
    public String longestPalindrome(String s) {
        StringBuffer sb = new StringBuffer("#");
		int len = s.length();
		for (int i = 0; i < len; i++)
			sb.append(s.charAt(i)).append('#');
		s = sb.toString();
		int maxLen = 1;
		len = s.length();
		int maxCenter = 1;
		for (int center = 2; center + maxLen < len; center++)
		{
			int j = 1;
			for (; center - j >= 0 && center + j < len; j++)
				if (s.charAt(center - j) != s.charAt(center + j))
					break;
			j--;
			if (j > maxLen)
			{
				maxLen = j;
				maxCenter = center;
			}
		}
		String maxAns = s.substring(maxCenter - maxLen, maxCenter + maxLen + 1);
		len = maxAns.length() / 2;
		sb = new StringBuffer();
		for (int i = 0; i < len; i++)
			sb.append(maxAns.charAt(i * 2 + 1));
		return sb.toString();
    }
}
