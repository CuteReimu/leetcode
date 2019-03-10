class Solution {
public:
	int clumsy(int N) {
		if (N == 1) return 1;
		if (N == 2) return 2 * 1;
		int ans = 1;
		ans *= N--;
		ans *= N--;
		ans /= N--;
		while (true) {
			if (N == 0) break;
			ans += N--;
			if (N == 0) break;
			if (N == 1) {
				ans -= 1;
				break;
			}
			if (N == 2) {
				ans -= 2 * 1;
				break;
			}
			if (N == 3) {
				ans -= 3 * 2 / 1;
				break;
			}
			int tmp = N--;
			tmp *= N--;
			tmp /= N--;
			ans -= tmp;
		}
		return ans;
	}
};
