class Solution {
public:
    int compareVersion(string version1, string version2) {
        int a;
        int b;
        int i = 0;
        int j = 0;
        while (true) {
            a = 0;
            b = 0;
            for (; i < version1.length(); i++) {
                if (version1[i] != '.') {
                    a *= 10;
                    a += version1[i] - '0';
                } else {
                    i++;
                    break;
                }
            }
            for (; j < version2.length(); j++) {
                if (version2[j] != '.') {
                    b *= 10;
                    b += version2[j] - '0';
                } else {
                    j++;
                    break;
                }
            }
            if (a > b) return 1;
            else if (a < b) return -1;
            if (i == version1.length() && j == version2.length()) {
                break;
            }
        }
        return 0;
    }
};
