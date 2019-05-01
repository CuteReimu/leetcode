class Solution {
public:
	int maxUncrossedLines(vector<int>& A, vector<int>& B) {
		vector<vector<int>> cache(A.size() + 1, vector<int>(B.size() + 1, 0));
		for (int i = 1; i <= A.size(); i++) {
			for (int j = 1; j <= B.size(); j++) {
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
				if (A[i - 1] == B[j - 1]) cache[i][j] = max(cache[i][j], cache[i - 1][j - 1] + 1);
			}
		}
		return cache.back().back();
	}
};
