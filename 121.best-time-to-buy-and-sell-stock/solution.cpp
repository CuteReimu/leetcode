class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int buy = INT_MAX;
        int result = 0;
        for (int i = 0; i < len; i++)
        {
            if (prices[i] > buy)
            {
                result = max(result, prices[i] - buy);
            } else if (prices[i] < buy)
            {
                buy = prices[i];
            }
        }
        return result;
    }
};
