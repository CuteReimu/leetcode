class Solution {
    struct cmp {
        bool operator()(const string &s1, const string &s2) const {
            int i = 0, j = 0;
            while (true) {
                if (s1[i] != s2[j]) return s1[i] < s2[j];
                i++;
                j++;
                if (i == s1.length() && j == s2.length()) return false;
                i %= s1.length();
                j %= s2.length();
            }
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        multiset<string, cmp> s;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            s.insert(toString(nums[i]));
        }
        string result;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            result += *it;
        }
        return result.length() > 1 && result[0] == '0' ? result.substr(0, 1) : result;
    }
private:
    string toString(int i) {
        if (i < 10) return string(1, '0' + i);
        return toString(i / 10) += i % 10 + '0';
    }
};
