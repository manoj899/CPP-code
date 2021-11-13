/*
n is the number of intervals
Time: O(nlogn)
Space: O(1) if we ignore res vector
*/


 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty())
            return {};
        
        sort(intervals.begin(), intervals.end(), 
             [](const Interval & l, const Interval & r) { 
                 return l.start < r.start;
             });
        
        vector<Interval> res;
        for (const auto & interval: intervals) {
            if (res.empty() || interval.start > res.back().end)
                res.push_back(interval);
            else
                res.back().end = max(res.back().end, interval.end);
        }
        return res;
    }
};