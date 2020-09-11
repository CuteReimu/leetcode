class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSum3(k, n, 10);
    }
private:
    vector<vector<int>> combinationSum3(int k, int n, int end) {
        vector<vector<int>> result;
        if (k == 0 && n == 0) {
            result.push_back(vector<int>());
            return result;
        }
        if (n <= 0 || k == 0) {
            return result;
        }
        for (int i = end - 1; i > 0; i--) {
            vector<vector<int>> result2 = combinationSum3(k - 1, n - i, i);
            for (auto &v : result2) {
                result.push_back(v);
                result.back().push_back(i);
            }
        }
        return result;
    }
};
