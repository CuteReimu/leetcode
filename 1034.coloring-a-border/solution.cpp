class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        vector<vector<int>> vec(grid.size(), vector<int>(grid.front().size(), 0));
        queue<pair<int, int>> q;
        q.push(make_pair(r0, c0));
        int c = grid[r0][c0];
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            if (vec[x][y] != 0) continue;
            vec[x][y]++;
            if (x > 0 && grid[x - 1][y] == c) {
                vec[x][y]++;
                q.push(make_pair(x - 1, y));
            }
            if (x < grid.size() - 1 && grid[x + 1][y] == c) {
                vec[x][y]++;
                q.push(make_pair(x + 1, y));
            }
            if (y > 0 && grid[x][y - 1] == c) {
                vec[x][y]++;
                q.push(make_pair(x, y - 1));
            }
            if (y < grid.front().size() - 1 && grid[x][y + 1] == c) {
                vec[x][y]++;
                q.push(make_pair(x, y + 1));
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid.front().size(); j++) {
                if (vec[i][j] != 5 && vec[i][j] != 0 && grid[i][j] == c) grid[i][j] = color;
            }
        }
        return grid;
    }
};
