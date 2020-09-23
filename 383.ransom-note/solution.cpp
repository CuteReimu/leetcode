class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> charcache;
		for (char i : magazine)
			charcache.insert(make_pair(i, 0)).first->second++;
        for (char i : ransomNote) {
            auto it = charcache.find(i);
            if (it == charcache.end() || !it->second) return false;
            it->second--;
        }
		return true;
    }
};
