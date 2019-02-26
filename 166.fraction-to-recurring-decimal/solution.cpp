class Solution {
public:
	string fractionToDecimal(long long numerator, long long denominator) {
		if (numerator == 0) return "0";
		bool isNegative = numerator > 0 ^ denominator > 0;
		numerator = abs(numerator);
		denominator = abs(denominator);
		long long remain = numerator % denominator;
		string result;
		long long ans = numerator / denominator;
		while (ans != 0) {
			result.insert(result.begin(), '0' + ans % 10);
			ans /= 10;
		}
		if (result.empty())
			result += '0';
		if (isNegative) result.insert(result.begin(), '-');
		if (remain == 0)
			return result;
		result += '.';
		map<long long, int> cache;
		while (remain != 0) {
			auto matchresult = cache.emplace(remain, result.length());
			if (!matchresult.second) {
				result.insert(next(result.begin(), matchresult.first->second), '(');
				result += ')';
				break;
			}
			remain *= 10;
			result += remain / denominator + '0';
			remain %= denominator;
		}
		return result;
	}
};
