class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int i = 0, j = 0;
		int cur = 0;
		int len = A.size();
		while (j < len) {
			if (A[j] == 0) cur++;
			if (cur > K) break;
			j++;
		}
		int result = j - i;
		while (j < len) {
			while (++j < len) {
				if (A[j] == 0) break;
			}
			while (true) {
				if (A[i++] == 0) break;
			}
			result = max(result, j - i);
		}
		return result;
	}
};
