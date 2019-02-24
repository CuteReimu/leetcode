class Solution {
	struct myline {
		myline(const Point &m, const Point &n) {
			b = (long long)m.x - (long long)n.x;
			a = (long long)n.y - (long long)m.y;
			c = a * m.x + b * m.y;
		}
		bool check(const Point &m) const {
			return a*m.x + b*m.y == c;
		}
		bool operator== (const myline &l) const {
			return a * l.b == b * l.a && a * l.c == c * l.a;
		}
		long long a;
		long long b;
		long long c;
	};
	struct cmp {
		size_t operator()(const myline &l) const {
			if (l.c == 0) {
				if (l.a == 0 || l.b == 0) return 0;
				else return min(l.a / l.b, l.b / l.a);
			}
			if (l.a == 0) return l.c * 10000 / l.b;
			return l.c * 10000 / l.a;
		}
	};
	struct cmp2 {
		bool operator()(const Point &p1, const Point &p2) const {
			return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
		}
	};
public:
	int maxPoints(vector<Point>& points) {
		if (points.empty()) return 0;
		map<Point, int, cmp2> pointcache;
		for (auto it = points.begin(); it != points.end(); it++) {
			pointcache.emplace(*it, 0).first->second++;
		}
		if (pointcache.size() == 1)
			return pointcache.begin()->second;
		unordered_map<myline, int, cmp> cache;
		for (auto it1 = pointcache.begin(); it1 != pointcache.end(); it1++) {
			unordered_set<myline, cmp> cache2;
			for (auto it2 = pointcache.begin(); it2 != pointcache.end(); it2++) {
				if (it1 == it2) continue;
				myline l(it1->first, it2->first);
				cache2.insert(l);
			}
			for (auto it2 = cache2.begin(); it2 != cache2.end(); it2++) {
				cache.emplace(*it2, 0).first->second += it1->second;
			}
		}
		int maxVal = 0;
		for (auto it = cache.begin(); it != cache.end(); it++) {
			maxVal = max(maxVal, it->second);
		}
		return maxVal;
	}
};
