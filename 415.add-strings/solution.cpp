class Solution {
public:
	string addStrings(string num1, string num2) {
		string s;
		int v = 0;
		for (int i = 1; ; i++) {
			if ((int) num1.size() - i < 0 && (int) num2.size() - i < 0) break;
			if ((int) num1.size() - i >= 0)
				v += num1[(int) num1.size() - i] - '0';
			if ((int) num2.size() - i >= 0)
				v += num2[(int) num2.size() - i] - '0';
			s += (char) (v % 10 + '0');
			v /= 10;
		}
		if (v > 0)
			s += '0' + v;
		reverse(s.begin(), s.end());
		return s;
	}
};
