/*
Leetcode task from https://leetcode.com/problems/wiggle-sort-ii/

Pseudo code (bruteforce):

sort the array
go till the middle and insert every el after mid between elements of first mid

for i in 0..arr.size / 2:
    res.push_back(arr[i])
    res.push_back(arr[arr.size i + arr.size/2])
*/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() > 1) {
            sort(nums.begin(), nums.end());

            vector<int> res;
            int i = nums.size() / 2 + nums.size() % 2 - 1;
            for (int j = nums.size() - 1; 
                 j > nums.size() / 2 + nums.size() % 2 - 1; --j) {
                res.push_back(nums[i--]);
                res.push_back(nums[j]);
            }
            if (nums.size() % 2) res.push_back(nums[0]);
            nums = res;
        }
    }
};

