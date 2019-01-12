class Solution {
public:
	string simplifyPath(string path) {
		string s("/");
		int index = 1;
		while (true)
		{
			if (index >= path.length()) break;
			int index2 = path.find('/', index);
			if (index2 == string::npos) index2 = path.length();
			string sub = path.substr(index, index2 - index);
			if (sub.empty() || sub == ".") {
			} else if (sub == "..") {
				s = s.substr(0, s.find_last_of('/'));
			} else {
				if (s.length() != 1) s += '/';
				s += sub;
			}
			index = index2 + 1;
			if (s.empty()) s += "/";
		}
		return s;
	}
};
