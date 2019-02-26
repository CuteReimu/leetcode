class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> vec(dungeon.size(), vector<int>(dungeon.front().size(), 0));
        vec.back().back() = min(dungeon.back().back(), 0);
        for (int i = dungeon.size() - 1; i >= 0; i--) {
            for (int j = dungeon.front().size() - 1; j >= 0; j--) {
                if (i == dungeon.size() - 1) {
                    if (j == dungeon.front().size() - 1) continue;
                    else vec[i][j] = vec[i][j + 1] + dungeon[i][j];
                } else {
                    if (j == dungeon.front().size() - 1) vec[i][j] = vec[i + 1][j] + dungeon[i][j];
                    else vec[i][j] = max(vec[i + 1][j], vec[i][j + 1]) + dungeon[i][j];
                }
                vec[i][j] = min(vec[i][j], 0);
            }
        }
        return 1 - vec[0][0];
    }
};
