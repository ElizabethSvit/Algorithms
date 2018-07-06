/*
Leetcode task from https://leetcode.com/problems/minimum-size-subarray-sum/description/

int start = 0
int end = 0
int min_len = nums.size() + 1

while (start <= end && end < nums.size)
    curr_sum += nums[end]
    if curr_sum < s
        end++
    else if curr_sum >= s
        min_len = min(min_len, end - start + 1)
        curr_sum -= nums[start]
        start--
if min_len is nums.size() + 1
    return 0
else return min_len

*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (!nums.size()) return 0;
        
        int start = 0;
        int end = 0;
        
        int min_len = nums.size() + 1;
        int curr_sum = nums[start];
        
        while (start <= end && end < nums.size()) {
            if (curr_sum < s) {
                end++;
                curr_sum += nums[end];
            }
            if (curr_sum >= s) {
                min_len = min(min_len, end - start + 1);
                curr_sum -= nums[start];
                start++;
            }
        }
        return min_len == nums.size() + 1 ? 0 : min_len;
    }
};

