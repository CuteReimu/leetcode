class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		return combine(n, k, n);
	}
	vector<vector<int>> combine(int n, int k, int end) {
		vector<vector<int>> vec;
		if (k == 1) {
			for (int i = 1; i <= end; i++)
				vec.push_back(vector<int>(1, i));
			return vec;
		}
		for (int i = end; i > 1; i--) {
			vector<vector<int>> result2 = combine(n, k - 1, i - 1);
			for (const vector<int>& v : result2) {
				vec.push_back(v);
				vec.back().push_back(i);
			}
		}
		return vec;
	}
};
