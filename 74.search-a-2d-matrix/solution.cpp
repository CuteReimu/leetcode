class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (!matrix.size()) return false;
		int m = matrix.size();
		int n = matrix.front().size();
		int beg = 0;
		int end = m;
		while (true)
		{
			if (beg == end - 1) return binary_search(matrix[beg].begin(), matrix[beg].end(), target);
			int mid = (beg + end) / 2;
			int &val = matrix[mid][0];
			if (val > target) end = mid;
			else if (val < target) beg = mid;
			else return true;
		}
	}
};
