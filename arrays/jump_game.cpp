/*
Leetcode task from https://leetcode.com/problems/jump-game
*/

class Solution {
public:
    
    // Recursive DFS solution with memoization (TL)
    /*
    set<int> mem;
    
    bool helper(vector<int>& nums, int start, set<int>& mem) {
        if (start == nums.size() - 1) return true;
        
        if (mem.count(start)) {
            return false;
        }
        
        for (int i = 1; i <= nums[start]; ++i) {
            if (start + i < nums.size()) {
                if (helper(nums, start + i, mem)) return true;
            } else {
                break;
            }
        }
        mem.insert(start);
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        
        return helper(nums, 0, mem);
    }
    */
    
    // Iterative super solution (check on each step if maxJump is enough)
    bool canJump(vector<int>& nums) {
        int max_jump = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (max_jump < i) {
                return false;
            }
            max_jump = max(max_jump, i + nums[i]);
        }
        return true;
    }
};

