/*
Leetcode task from https://leetcode.com/problems/target-sum/description/

Pseudo code (recursion):

recursion(curr_sum, S, nums, i)
    if i == nums size
        return curr sum == S

    return recursion(curr_sum + nums[i], S, nums, i + 1) + recursion(curr_sum - nums[i], S, nums, i + 1)
    
Dynamic programming:

for i in nums size:
    for el in dp[i-1]
        dp <- el - nums[i]
        dp <- el + nums[i]
        
for el in dp[n]
    count += (el == S)
return count

Optimized dynamic programming using dict <sum, counter of how many times seen>

*/

class Solution {
public:
    
    int recursive_helper(int curr_sum, int S, vector<int>& nums, int i) {
        if (i == nums.size()) {
            return curr_sum == S;
        }

        return recursive_helper(curr_sum + nums[i], S, nums, i + 1) +
            recursive_helper(curr_sum - nums[i], S, nums, i + 1);
    }
    
    
    int findTargetSumWays(vector<int>& nums, int S) {
        // DP
        
        /*
        vector<int> dp;
        dp.push_back(-nums[0]);
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            vector<int> next_dp;
            for (auto const& el: dp) {
                next_dp.push_back(el - nums[i]);
                next_dp.push_back(el + nums[i]);
            }
            dp = next_dp;
        }
        
        int counter = 0;
        for (auto const& el: dp) {
            counter += (el == S);
        }
        */
        
        // Optimized DP
        
        map<int, int> res;
        res[0] = 1;
        
        for (int el: nums) {
            map<int, int> count;
            for (auto const& p: res) {
                int res_value = res.count(p.first) ? res[p.first] : 0;
                count[p.first + el] += res_value;
                count[p.first - el] += res_value;
            }
            res = count;
        }
        
        return res.count(S) ? res[S] : 0;
        
        // Recursive
        // return recursive_helper(0, S, nums, 0);
    }
};

