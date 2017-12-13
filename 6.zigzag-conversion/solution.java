class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1)
            return s;
        int len = s.length();
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < numRows; i++)
        {
            if (i >= len)
                break;
        	sb.append(s.charAt(i));
        	for (int j = 1;; j++)
        	{
        		if (i != 0 && i != numRows - 1)
        		{
        			int index = j * (numRows - 1) * 2 - i;
        			if (index >= len)
        				break;
        			sb.append(s.charAt(index));
        		}
        		int index = i + j * (numRows - 1) * 2;
        		if (index >= len)
        			break;
        		sb.append(s.charAt(index));
        	}
        }
        return sb.toString();
    }
}
