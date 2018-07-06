/*
Leetcode task from https://leetcode.com/problems/kth-largest-element-in-an-array/description/

Using max heap.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; ++i) {
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        return nums.front();
    }
};

