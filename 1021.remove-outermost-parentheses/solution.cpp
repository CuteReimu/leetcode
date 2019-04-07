class Solution {
public:
    string removeOuterParentheses(string S) {
        string s;
        int i = 0;
        for (const char &c : S) {
            if (c == '(') {
                if (i++ > 0) {
                    s += c;
                }
            } else {
                if (--i > 0) {
                    s += c;
                }
            }
        }
        return s;
    }
};
