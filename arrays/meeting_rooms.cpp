/*
 Meeting rooms I
 
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 determine if a person could attend all meetings.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]], return false.
 
 Understand the problem:
 The problem looks very similar to the merge interval and insert intervals.
 So the idea is still the same: first sort the intervals according to the start times, then check if there is any overlap.
 
 Meeting rooms II
 
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei),
 find the minimum number of conference rooms required.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]], return 2.
 
 Pseudo code:
 
 init stack
 put first interval
 
 while not empty:
    if (top.end < current.start)
        while top.end < current.start:
            stack pop
        counter++
    else:
        put current in stack and counter++
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool meeting_rooms_i(vector<pair<int, int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); ++i) {
        if (i != intervals.size() - 1 && intervals[i].second > intervals[i+1].first) {
            return false;
        }
    }
    return true;
}

int meeting_rooms_ii(vector<pair<int, int>>& intervals) {
    if (intervals.size() < 2) return 1;
    
    sort(intervals.begin(), intervals.end());
    stack<pair<int, int>> rooms;
    int counter = 0;
    
    for (int i = 0; i < intervals.size(); ++i) {
        if (rooms.empty() || rooms.top().second > intervals[i].first) {
            rooms.push(intervals[i]);
        } else if (rooms.top().second < intervals[i].first) {
            while (!rooms.empty() && rooms.top().second < intervals[i].first) {
                rooms.pop();
            }
            counter++;
        }
    }
    return counter + static_cast<int>(rooms.size());
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> intervals = {{0, 4}, {5, 10}, {15, 20}};
    cout << meeting_rooms_ii(intervals);
    
    return 0;
}

