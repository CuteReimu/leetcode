#include <sstream>

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) {
                if (i % 5 == 0) v.emplace_back("FizzBuzz");
                else v.emplace_back("Fizz");
            } else if (i % 5 == 0) {
                v.emplace_back("Buzz");
            } else {
                stringstream ss;
                ss << i;
                string s;
                ss >> s;
                v.emplace_back(s);
            }
        }
        return v;
    }
};
