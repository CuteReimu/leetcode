class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int x = (matrix.size() + 1) / 2;
		int y = matrix.size() / 2;
		int xx = matrix.size() - 1;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				int tmp = matrix[j][i];
				matrix[j][i] = matrix[xx - i][j];
				matrix[xx - i][j] = matrix[xx - j][xx - i];
				matrix[xx - j][xx - i] = matrix[i][xx - j];
				matrix[i][xx - j] = tmp;
			}
		}
	}
};
