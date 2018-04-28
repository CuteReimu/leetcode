class Solution {
public:
    int strStr(string haystack, string needle) {
		string::size_type index = haystack.find(needle);
		return index == string::npos ? -1 : index;
    }
};
