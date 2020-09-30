class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size() % W != 0) return false;
        map<int, int> cache;
        for (int i : hand) cache.emplace(i, 0).first->second++;
        while (!cache.empty()) {
            int minval = cache.begin()->first;
            for (int i = minval; i < minval + W; i++) {
                auto it = cache.find(i);
                if (it == cache.end()) return false;
                if (--it->second == 0) cache.erase(it);
            }
        }
        return true;
    }
};
