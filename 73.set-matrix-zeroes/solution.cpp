class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		set<int> cacheI;
		set<int> cacheJ;
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix.front().size(); j++)
			{
				if (!matrix[i][j])
				{
					cacheI.insert(i);
					cacheJ.insert(j);
					for (int k = 0; k < i; k++) matrix[k][j] = 0;
					for (int k = 0; k < j; k++) matrix[i][k] = 0;
				} else
				{
					if (cacheI.find(i) != cacheI.end()) matrix[i][j] = 0;
					else if (cacheJ.find(j) != cacheJ.end()) matrix[i][j] = 0;
				}
			}
		}
	}
};
