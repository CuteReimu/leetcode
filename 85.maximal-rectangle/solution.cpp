class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty())
			return 0;
		int w = matrix.front().size();
		matrix.emplace_back(w, 0);
		int h = matrix.size();
		int result = 0;
		list<pair<int, int>> cache;
		for (int j1 = 0; j1 < w; j1++)
		{
			cache.clear();
			for (int i2 = 0; i2 < h;)
			{
				int count = 0;
				for (int j2 = j1; j2 < w && matrix[i2][j2] == '1'; j2++)
					count++;
				if (cache.empty() || count >= cache.back().second)
				{
					cache.emplace_back(i2, count);
					i2++;
				} else
				{
					int height = cache.back().second;
					cache.pop_back();
					int area = height * (cache.empty() ? i2 : i2 - cache.back().first - 1);
					result = area > result ? area : result;
				}
			}
		}
		return result;
	}
};
