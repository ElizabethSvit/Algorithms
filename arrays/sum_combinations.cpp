/*
Leetcode task from https://leetcode.com/problems/combination-sum-iv/description/

Pseudo code:

sort array

Dynamic programming:

init array dp with size of array + 1
dp[0] = 1

for t in 1..target:
    for i in nums:
        if t >= nums[i]
            dp[t] += dp[t - nums[i]]
return dp[target]
    
*/

class Solution {
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int t = 1; t <= target; ++t) {
            for (int j = 0; j < nums.size(); ++j) {
                if (t >= nums[j]) {
                    dp[t] += dp[t - nums[j]];
                }
            }
        }
        return dp[target];
        
    }
};

