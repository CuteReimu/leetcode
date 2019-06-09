class Solution {
public:
    int numTilePossibilities(string tiles) {
		return possibilities(tiles).size();
    }
private:
	unordered_set<string> possibilities(string tiles) {
		unordered_set<string> result;
		if (tiles.length() == 1) 
		{
			result.insert("" + tiles);
			return result;
		}
		for (int i = 0; i < tiles.length(); i++) {
			char ch = tiles[i];
			string str = tiles;
			str.erase(next(str.begin(), i));
			unordered_set<string> result2 = possibilities(str);
			for (string str2 : result2) {
				result.insert(str2 + ch);
			}
			result.insert(result2.begin(), result2.end());
		}
		return result;
	}
};
