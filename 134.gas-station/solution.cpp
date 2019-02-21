class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, len = gas.size(), needMore = 0, start = 0;
        for (int i = 0; i < len; i++) {
            sum += gas[i] - cost[i];
            if (sum < 0) {
                needMore -= sum;
                sum = 0;
                start = i + 1;
            }
        }
        return needMore <= sum ? start : -1;
    }
};
