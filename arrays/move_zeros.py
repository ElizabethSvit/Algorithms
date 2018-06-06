/*
Leetcode task https://leetcode.com/problems/move-zeroes/description/

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

/* Brute force solution with O(1) space and O(n^2) time complexity 

    Pseudo code

    init start = 0
    init end = nums size - 1

    while start < end:
        if nums[start] == 0:
            move nums[start] to the end position (bubble)
            end = end - 1
        start = start + 1
    */
    
    void moveZeroesBf(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start < end) {
            if (nums[start] == 0) {
                int curr_pos = start;
                while (curr_pos < end) {
                    swap(nums[curr_pos], nums[curr_pos+1]);
                    curr_pos++;
                }
                end--;
            } else {
                start++;
            }
        }
    }
    
    /* Optimal one with O(1) space and O(n) time complexity 
    
    Pseudo code
    
    init last_non_zero_ptr = 0
    
    for i in nums:
        if nums[i] != 0:
            swap nums[i] with nums[last_non_zero_ptr++]
    */
    
    void moveZeroes(vector<int>& nums) {
        int last_non_zero_ptr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) swap(nums[i], nums[last_non_zero_ptr++]);
        }
    }

