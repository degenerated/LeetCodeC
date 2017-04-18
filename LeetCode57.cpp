// LeetCode57.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) :start(s), end(e) {}
};
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval>res;
		int size = intervals.size();
		if (size == 0) { res.push_back(newInterval); return res; };
		int start = newInterval.start;
		int end = newInterval.end;
		//exception
		if (end < intervals[0].start) {
			intervals.insert(intervals.begin(), newInterval);
			return intervals;
		}
		if (start > intervals[size - 1].end) {
			intervals.push_back(newInterval);
			return intervals;
		}
		for (int i = 0; i < size; i++) {
			if (start > intervals[i].end) {
				res.push_back(intervals[i]);
			}
			else {
				if (end<intervals[i].start) {
					intervals.insert(intervals.begin() + i, newInterval);
					return intervals;
				}
				else if (start <= intervals[i].start&&end <= intervals[i].end) {
					intervals[i].start = start;
					return intervals;
				}
				else if (start >= intervals[i].start&&end <= intervals[i].end) {
					return intervals;
				}
				else {
					start = min(start, intervals[i].start);
					end = max(end, intervals[i].end);
					while (i < size&&end >= intervals[i].start) {
						end = max(end, intervals[i].end);
						i++;
					}
					newInterval.start = start;
					newInterval.end = end;
					res.push_back(newInterval);
					while (i < size) {
						res.push_back(intervals[i]);
						i++;
					}
				}
			}
		}
		return res;
	}
};
int main()
{
	vector<Interval> vsou;
	Interval v1 = Interval(1, 2); vsou.push_back(v1);
	Interval v2 = Interval(3, 5); vsou.push_back(v2);
	Interval v3 = Interval(6, 7); vsou.push_back(v3);
	Interval v4 = Interval(8, 10); vsou.push_back(v4);
	Interval v5 = Interval(12, 16); vsou.push_back(v5);
	Interval insert = Interval(4, 9);
	Solution a;

	vsou = a.insert(vsou, insert);
	for each (Interval i in vsou) {
		cout << i.start << " - " << i.end << endl;
	}
	return 0;
}

