class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec(rowIndex + 1);
        vec.front() = 1;
        vec.back() = 1;
        long val = 1;
        int mid = (rowIndex + 1) / 2;
        for (int i = 1; i <= mid; i++)
        {
            val = val * (rowIndex + 1 - i) / i;
            vec[i] = (int) val;
            vec[rowIndex - i] = (int) val;
        }
        return vec;
    }
};
