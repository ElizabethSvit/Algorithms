/*
Leetcode task from https://leetcode.com/problems/merge-intervals/description/

Pseudo code:

sort intervals by start

init merged_intervals
min_start = intervals[0].start
max_end = intervals[0].end

for i in 1..n:
    if (intervals[i].start >= min_start && intervals[i].start <= max_end)
        max_end = max(max_end, intervals[i].end)
    else 
        merged_intervals.push_back({min_start, max_end})
        min_start = intervals[i].start
        max_end = intervals[i].end
return merged_intervals   
*/

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
    
    static bool begining_sort(Interval first, Interval second) {
        return first.start < second.start;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> merged_intervals;
        if (!intervals.size()) return merged_intervals;
        
        sort(intervals.begin(), intervals.end(), begining_sort);
        int min_start = intervals[0].start;
        int max_end = intervals[0].end;
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start >= min_start && intervals[i].start <= max_end) {
                max_end = max(max_end, intervals[i].end);
            } else {
                merged_intervals.push_back(Interval(min_start, max_end));
                min_start = intervals[i].start;
                max_end = intervals[i].end;
            }
        }
        merged_intervals.push_back(Interval(min_start, max_end));
        return merged_intervals;
        
    }
};

