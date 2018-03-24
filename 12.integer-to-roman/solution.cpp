class Solution {
public:
    string intToRoman(int num) {
		static char *b[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, {"", "M", "MM", "MMM"}};
		int a[4];
		a[0] = num % 10;
		num /= 10;
		a[1] = num % 10;
		num /= 10;
		a[2] = num % 10;
		a[3] = num / 10;
		string ans;
		ans += b[3][a[3]];
		ans += b[2][a[2]];
		ans += b[1][a[1]];
		ans += b[0][a[0]];
		return ans;
    }
};
