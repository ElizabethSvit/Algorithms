/*
Leetcode task from https://leetcode.com/problems/total-hamming-distance/description/

Brute force: count distances for every pair and return sum
O(n) time complexity: 

For each bit in 32:
    if k nums contain this bit => hamming distance = (n-k) * k
*/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count = 0;
        int res_count = 0;
        
        for (int i = 0; i < 32; ++i) {
            count = 0;
            for (int num: nums) {
                count += ((num >> i) & 1);
            }
            res_count += (count * (nums.size() - count));
        }
        return res_count;
    }
};

