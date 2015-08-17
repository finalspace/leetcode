// Source : https://leetcode.com/problems/merge-intervals/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given a collection of intervals, merge all overlapping intervals.
* 
* For example,
* Given [1,3],[2,6],[8,10],[15,18],
* return [1,6],[8,10],[15,18].
* 
*               
**********************************************************************************/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 //580ms (very good)
class Solution {
public:
    static bool comp (Interval intv1, Interval intv2) {
		return (intv1.start < intv2.start) || ((intv1.start == intv2.start) && (intv1.end < intv2.end));
	}
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
		if (intervals.empty()) { return res; }
		sort(intervals.begin(), intervals.end(), comp);
		Interval curIntv = intervals[0];
		for (int i = 1; i < intervals.size(); i++) {
			if (curIntv.end < intervals[i].start) { res.push_back(curIntv); curIntv = intervals[i]; continue; }
			curIntv.end = max(curIntv.end, intervals[i].end);
		}
		res.push_back(curIntv);
		return res;
    }
};
