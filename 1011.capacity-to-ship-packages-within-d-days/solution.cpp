class Solution {
public:
	int shipWithinDays(vector<int>& weights, int D) {
		int sum = 0, maxVal = 0;
		for (const int &i : weights) {
			sum += i;
			maxVal = max(i, maxVal);
		}
		int n = max((sum - 1) / D + 1, maxVal);
		while (true) {
			int cur = 0, d = 1;
			for (const int &i : weights) {
				if (cur + i > n) {
					cur = 0;
					d++;
				}
				cur += i;
			}
			if (d <= D) break;
			n++;
		}
		return n;
	}
};
