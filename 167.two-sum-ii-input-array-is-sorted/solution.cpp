class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int ans = numbers[i] + numbers[j] - target;
            if (ans == 0) break;
            else if (ans > 0) j--;
            else i++;
        }
        vector<int> result;
        result.push_back(i + 1);
        result.push_back(j + 1);
        return result;
    }
};
