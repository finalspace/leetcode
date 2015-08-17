// Source : https://leetcode.com/problems/insert-interval/
// Author : Siyuan Xu
// Date   : 2015-08-12

/********************************************************************************** 
* 
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
* 
* You may assume that the intervals were initially sorted according to their start times.
* 
* Example 1:
* Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
* 
* Example 2:
* Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
* 
* This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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
 
 //588ms(medium)
class Solution1 {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       vector<Interval> res;
		vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end()) {
			if (it->end < newInterval.start) { res.push_back(*it); it++; continue; }
			else if (it->start > newInterval.end) { break; }
			else {
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
				it++;
			}
		}
		res.push_back(newInterval);
		/*
		while (it != intervals.end()) {
			res.push_back(*it++);
		}
		*/
		res.insert(res.end(), it, intervals.end());
		return res;
    }
};

//584ms(medium)
class Solution2 {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       vector<Interval> res;
		vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end()) {
			if (it->end < newInterval.start) { res.push_back(*it); it++; continue; }
			else if (it->start > newInterval.end) { break; }
			else {
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
				it++;
			}
		}
		res.push_back(newInterval);
		while (it != intervals.end()) {
			res.push_back(*it++);
		}
		//res.insert(res.end(), it, intervals.end());
		return res;
    }
};

//600ms
class Solution3 {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       vector<Interval> ret;
    int i = 0;
    for (i = 0; i < intervals.size(); i++)
    {        
        // If newInterval is BEHIND the current interval
        if (newInterval.start > intervals[i].end) 
            ret.push_back(intervals[i]); // then the current interval goes to the result
        // If new Interval is BEFORE the current interval
        else if (newInterval.end < intervals[i].start) 
        {
            ret.push_back(newInterval); // then new interval goes to the result
            newInterval = intervals[i]; // and save the current interval for later
        }
        else // If newInterval OVERLAPS WITH the current interval
        {
            // Then simply merge the two intervals.
            newInterval.start = min(newInterval.start, intervals[i].start);
            newInterval.end = max(newInterval.end, intervals[i].end);
        }
    }
    // In the end, there will be one interval that is still not stored in the result; and this interval, regardless where it comes from the vector or the newInterval, must be stored in newInterval at this point.
    ret.push_back(newInterval);
    return ret;
    }
};

//576ms(very good)
class Solution4 {
    private:

  // Merge the new interval with an array of intervals, all intervals in the 
  // array equal with the new interval in terms of the partial order we 
  // defined.
  // In other words all of them are overlapped with the new interval.

  Interval mergeEqual(const std::vector<Interval>::iterator & first, const std::vector<Interval>::iterator & last, const Interval &target){

    Interval answer(target);
    if(first < last){
      answer = merge(answer, *first);
      answer = merge(answer, *(last-1));
    }
    return answer;
  }
  // Merge two overlapped intervals.
  Interval merge(const Interval & a, const Interval & b) {
    return Interval(std::min(a.start, b.start), std::max(a.end, b.end));
  }
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
       auto partial_order =[](const Interval & a, const Interval & b){
      return a.end < b.start;
    };

    auto less = std::lower_bound(intervals.begin(), intervals.end(), newInterval, partial_order);

    auto greater = std::upper_bound(intervals.begin(), intervals.end(), newInterval, partial_order);
    //printf("The index position: %d %d\n", less - intervals.begin(), greater - intervals.begin());
    std::vector<Interval> answer; 

    answer.insert(answer.end(), intervals.begin(), less);
    answer.push_back(mergeEqual(less, greater, newInterval));
    answer.insert(answer.end(), greater, intervals.end());
    return answer;
    }
};
