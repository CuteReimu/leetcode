class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		if (triangle.size() == 1) return triangle[0][0];
		vector<int> vec(triangle.back().begin(), triangle.back().end());
		for (int i = triangle.size() - 2; i >= 0; i--)
		{
			for (int j = 0; j <= i; j++)
				vec[j] = triangle[i][j] + min(vec[j], vec[j + 1]);
		}
		return vec[0];
	}
};
