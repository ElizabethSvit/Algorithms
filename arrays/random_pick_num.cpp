/*
Leetcode task from https://leetcode.com/problems/random-pick-index/description/

Slow solution with unordered hash map.
*/

class Solution {
public:
    unordered_map<int, vector<int>> indeces;
    
    Solution(vector<int> nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (!indeces.count(nums[i])) {
                vector<int> inds;
                inds.push_back(i);
                indeces[nums[i]] = inds;
            }
            else indeces[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        vector<int> inds = indeces[target];
        return inds[rand() % inds.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */

