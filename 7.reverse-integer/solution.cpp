class Solution {
public:
    int reverse(int x) {
		int sign = x < 0 ? -1 : x > 0;
		x = abs(x);
		long answer = 0;
		while (x > 0)
		{
			answer = answer * 10 + x % 10;
			x /= 10;
		}
		answer *= sign;
		return answer > INT_MAX || answer < INT_MIN ? 0 : (int) answer;
    }
};
