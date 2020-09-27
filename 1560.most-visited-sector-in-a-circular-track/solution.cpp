class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> result;
        int i = rounds.front();
        while (true) {
            result.push_back(i);
            if (i == rounds.back()) break;
            i++;
            if (i > n) i -= n;
        }
        sort(result.begin(), result.end());
        return result;
    }
};
