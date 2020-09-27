int operator-(const vector<int> &vec1, const vector<int> &vec2) {
    int a = vec1[0] - vec2[0], b = vec1[1] - vec2[1];
    return a * a + b * b;
}

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int sum = 0;
        for (const vector<int> &vec1 : points) {
            map<int, int> cache;
            for (const vector<int> &vec2 : points)
                cache.emplace(vec2-vec1,0).first->second++;
            for (auto &p : cache)
                sum += p.second * (p.second - 1);
        }
        return sum;
    }
};
