class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (k == 0 || prices.empty()) return 0;
		if (k >= prices.size() / 2)
		{
			int max = 0;
			for(int i = 1; i < prices.size(); ++i) {
				if(prices[i] > prices[i-1])
					max += prices[i] - prices[i-1];
			}
			return max;
		}
		vector<int> buy(k, INT_MIN), sell(k, 0);
		for (int i = 0; i < prices.size(); i++)
		{
			int price = prices[i];
			buy[0] = max(buy[0], -price);
			sell[0] = max(sell[0], buy[0] + price);
			for (int j = 1; j < k; j++)
			{
				buy[j] = max(buy[j], sell[j - 1] - price);
				sell[j] = max(sell[j], buy[j] + price);
			}
		}
		return sell.back();
	}
};
