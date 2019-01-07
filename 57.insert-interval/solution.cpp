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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
		if (intervals.empty())
		{
			result.push_back(newInterval);
			return result;
		}
		vector<Interval>::iterator it1 = lower_bound(intervals.begin(), intervals.end(), newInterval.start, [](const Interval &interval, int i)->bool{return interval.end < i;});
		vector<Interval>::iterator it3 = upper_bound(intervals.begin(), intervals.end(), newInterval.end, [](int i, const Interval &interval)->bool{return interval.start > i;});
		vector<Interval>::iterator it2 = it3 - 1;
		result.insert(result.end(), intervals.begin(), it1);
		result.emplace_back(it1 != intervals.end() && it1->start < newInterval.start ? it1->start : newInterval.start,
			it2->end > newInterval.end ? it2->end : newInterval.end);
		result.insert(result.end(), it3, intervals.end());
		return result;
    }
};
