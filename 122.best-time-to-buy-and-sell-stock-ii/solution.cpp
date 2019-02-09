class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int result = 0;
        for (int i = 1; i < len; i++)
        {
            if (prices[i - 1] < prices[i])
                result += prices[i] - prices[i - 1];
        }
        return result;
    }
};
