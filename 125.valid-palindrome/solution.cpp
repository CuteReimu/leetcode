class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            char c = s[i];
            if (!(c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')) {
                i++;
                continue;
            }
            c = s[j];
            if (!(c >= '0' && c <= '9' || c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')) {
                j--;
                continue;
            }
            if (s[i] == c || c >= 'A' && c <= 'Z' && s[i] - c == 32 || c >= 'a' && c <= 'z' && c - s[i] == 32) {
                i++;
                j--;
                continue;
            }
            return false;
        }
        return true;
    }
};
