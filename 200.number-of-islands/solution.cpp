class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid.front().size();
        vector<vector<bool>> searched(rows, vector<bool>(cols, false));
        int num = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!searched[i][j] && grid[i][j] == '1') {
                    num++;
                    fillLands(grid, searched, i, j);
                }
            }
        }
        return num;
    }
private:
    void fillLands(const vector<vector<char>>& grid, vector<vector<bool>>& searched, int i, int j) {
        searched[i][j] = true;
        if (i > 0 && !searched[i - 1][j]) {
            if (grid[i - 1][j] == '1')
                fillLands(grid, searched, i - 1, j);
            else
                searched[i - 1][j] = true;
        }
        if (i < grid.size() - 1 && !searched[i + 1][j]) {
            if (grid[i + 1][j] == '1')
                fillLands(grid, searched, i + 1, j);
            else
                searched[i + 1][j] = true;
        }
        if (j > 0 && !searched[i][j - 1]) {
            if (grid[i][j - 1] == '1')
                fillLands(grid, searched, i, j - 1);
            else
                searched[i][j - 1] = true;
        }
        if (j < grid.front().size() - 1 && !searched[i][j + 1]) {
            if (grid[i][j + 1] == '1')
                fillLands(grid, searched, i, j + 1);
            else
                searched[i][j + 1] = true;
        }
    }
};
