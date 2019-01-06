/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        map<int, int> cache;
		for (Interval &i : intervals)
		{
			map<int, int>::iterator it = cache.find(i.start);
			if (it == cache.end())
				cache.emplace(i.start, 1);
			else
				it->second++;
			it = cache.find(i.end);
			if (it == cache.end())
				cache.emplace(i.end, -1);
			else
				it->second--;
		}
		vector<Interval> result;
		int start;
		int level = 0;
		for (pair<const int, int> &p : cache)
		{
			int oldLevel = level;
			level += p.second;
			if (!oldLevel)
				start = p.first;
			if (!level)
				result.emplace_back(start, p.first);
		}
		return result;
    }
};
