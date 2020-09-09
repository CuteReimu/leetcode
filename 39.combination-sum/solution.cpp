class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return combinationSum(candidates, target, 0);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target, int begin) {
        vector<vector<int>> result;
        for (int i = begin; i < candidates.size(); i++) {
            if (candidates[i] == target)
                result.push_back(vector<int>(1, target));
            else if (candidates[i] < target)
            {
                vector<vector<int>> result2 = combinationSum(candidates, target - candidates[i], i);
                for (auto &v : result2) {
                    result.push_back(v);
                    result.back().push_back(candidates[i]);
                }
            }
        }
        return result;
    }
};
