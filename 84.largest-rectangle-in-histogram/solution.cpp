class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> cache;
		heights.push_back(0);
		int len = heights.size();
		int result = 0;
		for (int i = 0; i < len;)
		{
			if (cache.empty() || heights[i] >= heights[cache.top()])
			{
				cache.push(i);
				i++;
			} else
			{
				int idx = cache.top();
				cache.pop();
				int area = heights[idx]*(cache.empty()?i:(i-cache.top()-1));
				result = area > result ? area : result;
			}
		}
		return result;
	}
};
