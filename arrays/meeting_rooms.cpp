/*
 Meeting rooms
 
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 determine if a person could attend all meetings.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]], return false.
 
 Understand the problem:
 The problem looks very similar to the merge interval and insert intervals.
 So the idea is still the same: first sort the intervals according to the start times, then check if there is any overlap.
 */

#include <iostream>
#include <vector>

using namespace std;

bool meeting_rooms(vector<pair<int, int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); ++i) {
        if (i != intervals.size() - 1 && intervals[i].second > intervals[i+1].first) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> intervals = {{0, 4}, {5, 10}, {15, 20}};
    cout << meeting_rooms(intervals);
    
    return 0;
}

