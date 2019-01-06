class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		if (matrix.empty()) return result;
		int i = 0, j = -1, dir = 0;
		int goal;
		int left = 0;
		while (true)
		{
			switch (dir)
			{
			case 0:
				goal = matrix.front().size() - 1 - left;
				if (goal <= j) return result;
				for (j++; j <= goal; j++) result.push_back(matrix[i][j]);
				j--;
				break;
			case 1:
				goal = matrix.size() - 1 - left;
				if (goal <= i) return result;
				for (i++; i <= goal; i++) result.push_back(matrix[i][j]);
				i--;
				break;
			case 2:
				goal = left;
				if (goal >= j) return result;
				for (j--; j >= goal; j--) result.push_back(matrix[i][j]);
				j++;
				break;
			case 3:
				goal = ++left;
				if (goal >= i) return result;
				for (i--; i >= goal; i--) result.push_back(matrix[i][j]);
				i++;
			}
			dir = (dir + 1) % 4;
		}
		return result;
	}
};
