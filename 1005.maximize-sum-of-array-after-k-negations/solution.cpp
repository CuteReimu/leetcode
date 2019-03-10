class Solution {
public:
	int largestSumAfterKNegations(vector<int>& A, int K) {
		sort(A.begin(), A.end());
		for (auto it = A.begin(); it != A.end();) {
			if (K <= 0) break;
			if (*it < 0) {
				*it = -*it;
				K--;
				it++;
			} else if (*it == 0) {
				break;
			} else {
				if (K % 2 != 0) {
					if (it != A.begin() && *(it - 1) < *it)
						it--;
					*it = -*it;
				}
				break;
			}
		}
		int sum = 0;
		for (auto it = A.begin(); it != A.end(); it++) {
			sum += *it;
		}
		return sum;
	}
};
