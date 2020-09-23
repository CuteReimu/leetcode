class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size() / 2;
        int len2 = s.size();
        for (int i = 0; i < len; i++) {
            char tmp = s[i];
            s[i] = s[len2 - i - 1];
            s[len2 - i - 1] = tmp;
        }
    }
};
