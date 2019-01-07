class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		if (!n) return vector<vector<int>>();
		vector<vector<int>> matrix(n, vector<int>(n));
		int i = 0, j = -1, dir = 0;
		int goal;
		int left = 0;
		int cur = 0;
		while (true)
		{
			switch (dir)
			{
			case 0:
				goal = matrix.front().size() - 1 - left;
				if (goal <= j) return matrix;
				for (j++; j <= goal; j++) matrix[i][j] = ++cur;
				j--;
				break;
			case 1:
				goal = matrix.size() - 1 - left;
				if (goal <= i) return matrix;
				for (i++; i <= goal; i++) matrix[i][j] = ++cur;
				i--;
				break;
			case 2:
				goal = left;
				if (goal >= j) return matrix;
				for (j--; j >= goal; j--) matrix[i][j] = ++cur;
				j++;
				break;
			case 3:
				goal = ++left;
				if (goal >= i) return matrix;
				for (i--; i >= goal; i--) matrix[i][j] = ++cur;
				i++;
			}
			dir = (dir + 1) % 4;
		}
		return matrix;
	}
};
