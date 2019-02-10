class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
        int buy0 = INT_MIN, sell0 = 0, buy1 = INT_MIN, sell1 = 0;
		for (int price : prices)
		{
			buy0 = max(buy0, -price);
			sell0 = max(sell0, buy0 + price);
            buy1 = max(buy1, sell0 - price);
            sell1 = max(sell1, buy1 + price);
		}
		return sell1;
	}
};
