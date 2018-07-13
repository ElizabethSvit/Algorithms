/*
Leetcode task from https://leetcode.com/problems/increasing-triplet-subsequence/description/

Pseudo code:

init first, second, third with max value

for element in array:
    if element < first: 
        first = element
    if element > first and element < second:
        second = element
    if element > second:
        return true
return false
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = first;
        
        for (int el: nums) {
            if (el < first) {
                first = el;
            }
            if (el > first && el < second) {
                second = el;
            }
            if (el > second) return true;
        }
        return false;
    }
};

