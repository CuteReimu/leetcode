class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> cache;
		for (const string &s : tokens) {
			switch (s[0]) {
			case '+':
				if (s.size() == 1) {
					int b = cache.top();
					cache.pop();
					int a = cache.top();
					cache.pop();
					cache.push(a + b);
				} else
					cache.push(strToInt(s));
				break;
			case '-':
				if (s.size() == 1) {
					int b = cache.top();
					cache.pop();
					int a = cache.top();
					cache.pop();
					cache.push(a - b);
				} else
					cache.push(-strToInt(s));
				break;
			case '*':
				{
					int b = cache.top();
					cache.pop();
					int a = cache.top();
					cache.pop();
					cache.push(a * b);
				}
				break;
			case '/':
				{
					int b = cache.top();
					cache.pop();
					int a = cache.top();
					cache.pop();
					cache.push(a / b);
				}
				break;
			default:
				cache.push(strToInt(s));
			}
		}
		return cache.top();
	}
private:
	int strToInt(const string &s) {
		int result = 0;
		for (const char &c : s) {
			if (c == '+' || c == '-') continue;
			result *= 10;
			result += c - '0';
		}
		return result;
	}
};
