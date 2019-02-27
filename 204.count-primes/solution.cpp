class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        set<int> cache;
        for (int i = 3; i < n; i += 2) {
            bool isPrime = true;
            for (int j : cache) {
                if (j * j > i) break;
                if (i % j == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) cache.insert(i);
        }
        return cache.size() + 1;
    }
};
