class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
        	return false;
        String s = String.valueOf(x);
        int len = s.length();
        int half = len / 2;
        for (int i = 0; i < half; i++)
        {
        	if (s.charAt(i) != s.charAt(len - 1 - i))
        		return false;
        }
        return true;
    }
}
