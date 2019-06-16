class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.front().front() != 0 || grid.back().back() != 0) return -1;
		vector<vector<int>> vec(grid.size(), vector<int>(grid.front().size(), -1));
		vec[0][0] = 1;
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		while (!q.empty()) {
			pair<int, int> p = q.front();
			if (p.first == grid.size() - 1 && p.second == grid.front().size() - 1) break;
			q.pop();
			int x, y;
			x = p.first - 1, y = p.second - 1;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] == 0 && vec[x][y] == -1) {
				q.push(make_pair(x, y));
				vec[x][y] = vec[p.first][p.second] + 1;
			}
			x = p.first, y = p.second - 1;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] == 0 && vec[x][y] == -1) {
				q.push(make_pair(x, y));
				vec[x][y] = vec[p.first][p.second] + 1;
			}
			x = p.first + 1, y = p.second - 1;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] == 0 && vec[x][y] == -1) {
				q.push(make_pair(x, y));
				vec[x][y] = vec[p.first][p.second] + 1;
			}
			x = p.first + 1, y = p.second;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] == 0 && vec[x][y] == -1) {
				q.push(make_pair(x, y));
				vec[x][y] = vec[p.first][p.second] + 1;
			}
			x = p.first + 1, y = p.second + 1;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] == 0 && vec[x][y] == -1) {
				q.push(make_pair(x, y));
				vec[x][y] = vec[p.first][p.second] + 1;
			}
			x = p.first, y = p.second + 1;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] == 0 && vec[x][y] == -1) {
				q.push(make_pair(x, y));
				vec[x][y] = vec[p.first][p.second] + 1;
			}
			x = p.first - 1, y = p.second + 1;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] == 0 && vec[x][y] == -1) {
				q.push(make_pair(x, y));
				vec[x][y] = vec[p.first][p.second] + 1;
			}
			x = p.first - 1, y = p.second;
			if (x >= 0 && y >= 0 && x < grid.size() && y < grid.front().size() && grid[x][y] == 0 && vec[x][y] == -1) {
				q.push(make_pair(x, y));
				vec[x][y] = vec[p.first][p.second] + 1;
			}
		}
		return vec.back().back();
    }
};
