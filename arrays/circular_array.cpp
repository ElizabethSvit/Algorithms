/*
Leetcode task from https://leetcode.com/problems/circular-array-loop/description/

Pseudo code

i = 0
forward = nums[0] > 0

while true:
    int index = nums[i]
    if index < 0:  
        index += nums size
    index %= nums size
    
    if index == 0
        return true
    
    if nums[i] > 0 and !forward or vice versa:
        return false
        

*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        if (nums.size() < 2) return false;
        int i = 0;
        bool forward = nums[i] > 0;
        int prev;
        
        while (true) {
            prev = i;
            i += nums[i];
            if (i < 0) i += nums.size();
            i %= nums.size();
            
            if (i == 0) {
                return true;
            }
            if ((nums[i] > 0 && !forward) || (nums[i] < 0 && forward) || i == prev) {
                return false;
            }
        }
    }
};

