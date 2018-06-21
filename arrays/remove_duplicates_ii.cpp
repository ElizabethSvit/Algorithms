/*
Leetcode task from https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

*/

class Solution {
public:
    int removeDuplicatesMy(vector<int>& nums) {
        if (!nums.size()) return 0;
        int i = 1;
        int left_ptr;
        
        if (nums.size() >= 2 && nums[0] == nums[1]) left_ptr = 2;
        else left_ptr = 1;
        
        while (i < nums.size()) {
            if (nums[i] != nums[i-1]) {
                nums[left_ptr++] = nums[i];
                if (i + 1 < nums.size() && nums[i+1] == nums[i]) {
                    nums[left_ptr++] = nums[i+1];
                    i++;
                }
            }
            i++;
        }
        
        return left_ptr; 
    }
    
    // Super small solution
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n: nums) {
            if (i < 2 || n > nums[i-2]) {
                nums[i++] = n;
            }
        }
        return i;
    }
    
};

