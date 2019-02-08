class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (!numRows) return result;
        result.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++)
        {
            result.emplace_back(i + 1);
            auto &last = result[result.size() - 2];
            auto &bk = result.back();
            bk[0] = 1;
            for (int j = 1; j < i; j++)
                bk[j] = last[j - 1] + last[j];
            bk[i] = 1;
        }
        return result;
    }
};
