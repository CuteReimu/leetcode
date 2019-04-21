class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result;
        for (int i = 0; i <= R + C - 2; i++) {
            for (int j = 0; j <= i; j++) {
                int x = abs(j);
                int y = i - x;
                if (y == 0) {
                    if (x == 0) {
                        vector<int> point;
                        point.push_back(r0);
                        point.push_back(c0);
                        result.push_back(point);
                    } else {
                        if (r0 + x < R)
                        {
                            vector<int> point;
                            point.push_back(r0 + x);
                            point.push_back(c0);
                            result.push_back(point);
                        }
                        if (r0 - x >= 0)
                        {
                            vector<int> point;
                            point.push_back(r0 - x);
                            point.push_back(c0);
                            result.push_back(point);
                        }
                    }
                } else {
                    if (x == 0) {
                        if (c0 + y < C)
                        {
                            vector<int> point;
                            point.push_back(r0);
                            point.push_back(c0 + y);
                            result.push_back(point);
                        }
                        if (c0 - y >= 0)
                        {
                            vector<int> point;
                            point.push_back(r0);
                            point.push_back(c0 - y);
                            result.push_back(point);
                        }
                    } else {
                        if (c0 + y < C && r0 + x < R) {
                            vector<int> point;
                            point.push_back(r0 + x);
                            point.push_back(c0 + y);
                            result.push_back(point);
                        }
                        if (c0 - y >= 0 && r0 + x < R) {
                            vector<int> point;
                            point.push_back(r0 + x);
                            point.push_back(c0 - y);
                            result.push_back(point);
                        }
                        if (c0 - y >= 0 && r0 - x >= 0) {
                            vector<int> point;
                            point.push_back(r0 - x);
                            point.push_back(c0 - y);
                            result.push_back(point);
                        }
                        if (c0 + y < C && r0 - x >= 0) {
                            vector<int> point;
                            point.push_back(r0 - x);
                            point.push_back(c0 + y);
                            result.push_back(point);
                        }
                    }
                }
            }
        }
        return result;
    }
};
