/*
Leetcode task from https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

Pseudo code

init left_ptr = 0
init right_ptr = 0

while (right_ptr < nums.size()):
    if nums[right_ptr] != nums[left_ptr]:
        nums[left_ptr++] = nums[right_ptr]
    right_ptr++
return left_ptr
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 1) return 0;
        
        int left_ptr = 0;
        int right_ptr = 1;
        
        while (right_ptr < nums.size()) {
            if (nums[right_ptr] != nums[right_ptr-1]) {
                left_ptr++;
                nums[left_ptr] = nums[right_ptr];
            }
            right_ptr++;
        }
        return left_ptr+1;
    }
};

