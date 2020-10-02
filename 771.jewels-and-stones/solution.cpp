class Solution {
public:
    int numJewelsInStones(string J, string S) {
        char cache[128] = {0};
        for (char c : J)
            cache[c]++;
        int sum = 0;
        for (char c : S)
            if (cache[c] > 0)
                sum++;
        return sum;
    }
};
