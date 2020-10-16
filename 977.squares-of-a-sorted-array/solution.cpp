class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> v;
        for (int i : A) {
            v.push_back(i * i);
        }
        sort(v.begin(), v.end());
        return v;
    }
};
