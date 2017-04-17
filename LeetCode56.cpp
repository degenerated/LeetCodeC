// LeetCode56.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool acompare(Interval l1, Interval l2) { return l1.start < l2.start; }
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		int size = intervals.size();
		if (size <= 1) return intervals;
		//sort(intervals.begin(), intervals.end());
		sort(intervals.begin(), intervals.end(), acompare);
		int s = intervals[0].start;
		int e = intervals[0].end;
		int cs, ce;
		for (int i = 1; i < size; i++) {
			cs = intervals[i].start;
			ce = intervals[i].end;
			if (cs > e) {
				Interval tmp = Interval(s, e);
				res.push_back(tmp);
				e = ce;
				s = cs;
			}
			else {
				e = max(e, ce);
				s = min(s, cs);
			}
		}
		Interval tmp = Interval(s, e);
		res.push_back(tmp);

		return res;
	}
};
int main()
{
	vector<Interval> vsou;
	Interval i1 = Interval(1, 3);
	Interval i2 = Interval(2, 6);
	Interval i3 = Interval(15, 18);
	Interval i4 = Interval(8, 10);
	vsou.push_back(i1); vsou.push_back(i2); vsou.push_back(i3); vsou.push_back(i4);
	Solution a;
	vector<Interval>res = a.merge(vsou);
	for each(Interval tmp in res) {
		cout << tmp.start << " - " << tmp.end<<endl;
	}
    return 0;
}

