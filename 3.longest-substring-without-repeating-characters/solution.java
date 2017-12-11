class Solution {
    public int lengthOfLongestSubstring(String s) {
    	int i = 0, j = 0;
    	while (j <= s.length()) {
    		if (!check(s, i, j))
    			i++;
    		j++;
    	}
    	return j - i - 1;
    }

    public boolean check(String s, int i, int j)
    {
    	if (i == j)
    		return true;
    	Set<Character> set = new HashSet<>();
    	for (; i < j; i++)
    	{
    		if (!set.add(s.charAt(i)))
    			return false;
    	}
    	return true;
    }
}
