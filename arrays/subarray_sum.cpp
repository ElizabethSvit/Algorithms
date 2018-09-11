/*
Leetcode task from https://leetcode.com/problems/continuous-subarray-sum/description/

Pseudo code:

[23, 2, 4, 6, 7]
[5, 2, 4, 0, 1]

go thru residuals and sum up:
5 (remember in map)
1
5 - same twice => was multiple by 6 (need to count how long ago - at least two)

*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> residuals;
        int res_sum = 0;
        residuals[0] = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            res_sum += nums[i];
            if (k != 0) res_sum %= k;
            if (residuals.count(res_sum)) {
                if (i - residuals[res_sum] > 1) {
                    return true;
                }
            } else residuals[res_sum] = i;
        }
        return false;
    }
};

