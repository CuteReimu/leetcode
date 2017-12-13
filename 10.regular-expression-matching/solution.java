class Solution {
    public boolean isMatch(String s, String p) {
        if (p.startsWith("*"))
			return isMatch(s, p.substring(1));
		if (p.isEmpty())
			return s.isEmpty();
		char cur = '\0';
		int j = 0;
        for (int i = 0; i < p.length(); i++)
        {
        	if (p.charAt(i) == '*') {
    			int curJ = j;
        		if (cur == '.')
        		{
        			j = s.length();
        		} else
        		{
        			j--;
        			while (++j < s.length() && s.charAt(j) == cur);
        		}
    			while (true)
    			{
    				if (isMatch(s.substring(j), p.substring(i + 1)))
    					return true;
    				j--;
    				if (j < curJ)
    					return false;
    			}
        	} else {
        		if (cur != '\0')
        		{
                	if (j >= s.length())
                		return false;
                	else if (cur == '.')
	        			j++;
	        		else if (s.charAt(j++) != cur)
	        			return false;
        		}
        		cur = p.charAt(i);
        	}
        }
        char last = p.charAt(p.length() - 1);
        if (last != '*')
        {
        	if (j >= s.length())
        		return false;
        	else if (cur == '.')
    			j++;
    		else if (s.charAt(j++) != cur)
    			return false;
        }
        return j == s.length();
    }
}
