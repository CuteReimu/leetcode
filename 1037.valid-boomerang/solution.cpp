class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<int> &i1 = points[0];
        vector<int> &i2 = points[1];
        vector<int> &i3 = points[2];
        if (i1 == i2 || i2 == i3 || i3 == i1) return false;
        if ((i1[0] - i2[0]) * (i2[1] - i3[1]) == (i2[0] - i3[0]) * (i1[1] - i2[1]))
            return false;
        return true;
    }
};
