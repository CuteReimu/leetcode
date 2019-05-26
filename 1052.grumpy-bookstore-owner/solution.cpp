class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int total = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            if (grumpy[i] == 0) total += customers[i];
        }
        int i = 0;
        for (; i < X; i++) {
            if (grumpy[i] == 1) total += customers[i];
        }
        int maxVal = total;
        for (; i < customers.size(); i++) {
            if (grumpy[i - X] == 1) total -= customers[i - X];
            if (grumpy[i] == 1) total += customers[i];
            maxVal = max(maxVal, total);
        }
        return maxVal;
    }
};
