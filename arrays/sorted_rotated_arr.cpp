/*
Leetcode task from https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int mid;
        
        while (start < end) {
            mid = (end - start) / 2 + start;
            // cout << "start" << start << "end" << end << endl;
            if (nums[mid] > target) {
                if (nums[start] > target && nums[start] < nums[mid]) start = mid+1;
                else if(nums[start] != target) end = mid;
                else return start;
            } else if (nums[mid] < target) {
                if (nums[start] < target && nums[start] > nums[mid]) end = mid;
                else if (nums[start] != target) start = mid+1;
                else return start;
            } else return mid;
        }
        return -1;
    }
};

