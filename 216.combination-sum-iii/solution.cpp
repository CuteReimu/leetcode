class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSum3(k, n, 10);
    }
private:
    vector<vector<int>> combinationSum3(int k, int n, int end) {
        vector<vector<int>> result;
        if (n <= 0) {
            return result;
        }
        if (k == 1) {
            result.push_back(vector<int>(1, n));
            return result;
        }
        int minval = k > 2 ? k : n / 2 + 1;
        for (int i = end - 1; i >= minval; i--) {
            vector<vector<int>> result2 = combinationSum3(k - 1, n - i, i);
            for (auto &v : result2) {
                result.push_back(v);
                result.back().push_back(i);
            }
        }
        return result;
    }
};
