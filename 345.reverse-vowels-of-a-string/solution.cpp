class Solution {
public:
    string reverseVowels(string s) {
        int i = -1, j = s.size();
        do {
            do { i++; } while (i < j && !isYuan(s[i]));
            do { j--; } while (i < j && !isYuan(s[j]));
            if (i >= j) break;
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        } while (true);
        return s;
    }
    bool isYuan(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            return true;
        }
        return false;
    }
};
