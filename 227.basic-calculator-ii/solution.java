class Solution {
	public int calculate(String s) {
		s = s.trim();
		if (s.charAt(0) == '+' || s.charAt(0) == '-')
			s = "0" + s;
		String[] arrs = s.split("[+-]");
		int val = calculate2(arrs[0]);
		int start = 0;
		for (int i = 1; i < arrs.length; i++) {
			int idx1 = s.indexOf('+', start);
			int idx2 = s.indexOf('-', start);
			idx1 = idx1 == -1 ? Integer.MAX_VALUE : idx1;
			idx2 = idx2 == -1 ? Integer.MAX_VALUE : idx2;
			int idx = Math.min(idx1, idx2);
			start = idx + 1;
			if (s.charAt(idx) == '+')
				val += calculate2(arrs[i]);
			else
				val -= calculate2(arrs[i]);
		}
		return val;
	}

	private int calculate2(String s) {
		s = s.trim();
		String[] arrs = s.split("[*/]");
		int val = Integer.parseInt(arrs[0].trim());
		int start = 0;
		for (int i = 1; i < arrs.length; i++) {
			int idx1 = s.indexOf('*', start);
			int idx2 = s.indexOf('/', start);
			idx1 = idx1 == -1 ? Integer.MAX_VALUE : idx1;
			idx2 = idx2 == -1 ? Integer.MAX_VALUE : idx2;
			int idx = Math.min(idx1, idx2);
			start = idx + 1;
			if (s.charAt(idx) == '*')
				val *= Integer.parseInt(arrs[i].trim());
			else
				val = Math.floorDiv(val, Integer.parseInt(arrs[i].trim()));
		}
		return val;
	}
}
