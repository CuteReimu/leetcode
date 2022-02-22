class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 != 0)
            return vector<long long>();
        num /= 3;
        long long nums[] = {num-1, num, num+1};
        return vector<long long>(nums, nums+3);
    }
};
