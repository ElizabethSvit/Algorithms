/*
Leetcode task from https://leetcode.com/problems/merge-sorted-array/description/

[1,2,3,0,0,0]
3
[2,5,6]
3

[1,2,3,0,0,0]
[2,5,6]


Pseudo code (brute force):

while i < m and j < n:
    if nums1[i] < nums2[j]:
        i++
    else if nums1[i] == nums2[j]:
        shift all the rest in nums1[i+1:] to the right by one
        input nums2[j] to nums1[i+1] 
        j++
    else:
        shift all the rest in nums1[i:] to the right by one
        input nums2[j] to nums1[i] 
        j++
return nums1

Pseudo code (efficient):

init i = m - 1
init j = n - 1
init k = m + n - 1

while (j >= 0):
    if i == -1 or nums2[j] > nums1[i]:
        nums1[k] = nums2[j]
        j--
    else:
        nums1[k] = nums1[i]
        i--
    k--

*/

class Solution {
public:
    
    void shift(vector<int> &nums1, int start, int curr_size) {
        for (int i = curr_size; i > start; --i) {
            nums1[i] = nums1[i-1];
        }
    }
    
    void merge_slow(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int curr_size1 = m;
        
        while (i < curr_size1 && j < n) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] == nums2[j]) {
                shift(nums1, i+1, curr_size1);
                nums1[i+1] = nums2[j];
                j++;
                curr_size1++;
            } else {
                shift(nums1, i, curr_size1);
                nums1[i] = nums2[j];
                j++;
                curr_size1++;
            }
        }
        while (j < n) {
            nums1[i] = nums2[j];
            i++;
            j++;
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i == -1 || nums2[j] > nums1[i]) {
                nums1[k] = nums2[j];
                j--;
            } else {
                nums1[k] = nums1[i];
                i--;
            }
            k--;
        }
    }
    
};

