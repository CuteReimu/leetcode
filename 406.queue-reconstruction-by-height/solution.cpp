class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
		sort(people.begin(), people.end(),
			[](const vector<int> &p1, const vector<int> &p2){return p1[1]!=p2[1]?p1[1]<p2[1]:p1[0]<p2[0];});
		for (int i = 0; i < people.size(); i++)
		{
			int cnt = 0;
			for (int j = 0; j < i; j++)
				if (people[j][0] >= people[i][0]) cnt++;
			int shouldCnt = people[i][1];
			for (int j = i - 1; cnt > shouldCnt && j >= 0; j--)
			{
				if (people[j][0] >= people[j + 1][0]) cnt--;
				vector<int> tmp = people[j];
				people[j] = people[j + 1];
				people[j + 1] = tmp;
			}
		}
		return people;
	}
};
