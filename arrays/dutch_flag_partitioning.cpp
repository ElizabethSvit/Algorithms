/*
Leetcode task from https://leetcode.com/problems/sort-colors/description/

Dutch national flag partitioning problem!

Pseudo code

red, white, blue = 0, 0, nums.size - 1

while white <= blue
    if nums[white] == 0
        swap(nums[white], nums[red])
        white++
        red++
    if nums[white] == 1
        white++
    if nums[white] == 2
        swap(nums[white], nums[blue])
        blue--
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = nums.size() - 1;
        
        while (white <= blue) {
            if (nums[white] == 0) {
                swap(nums[white], nums[red]);
                white++;
                red++;
            } else if (nums[white] == 1) white++;
            else {
                swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};

