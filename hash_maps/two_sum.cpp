/*

Leetcode task from https://leetcode.com/problems/two-sum/description/

Plan

Need to find x + y = k (given)
For current x: y = k - x => can do binary search to find y. The array should be sorted prior to that.

Pseudo code

save initial indexes in the separate array
sort the array
init start, end indexes

while start < end:
    if nums[start] + nums[end] > target:
        end--
    else if nums[start] + nums[end] < target:
        start++
    else
	check if integers are not same, if same -- store in different values
        return [indexes[nums[start]], indexes[nums[end]]]

Time complexity: O(nlogn)

Can be done faster with time complexity O(n): 
While we iterate and inserting elements into the table, we also look back 
to check if current element's complement already exists in the table. 
If it exists, we have found a solution and return immediately
    
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int> > indexes;
        
        for (int i = 0; i < nums.size(); ++i) {
            indexes[nums[i]].push_back(i);
        }
        
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = nums.size() - 1;
        
        while (start < end) {
            if (nums[start] + nums[end] > target) end--;
            else if (nums[start] + nums[end] < target) start++;
            else {
                int first_ind = indexes[nums[start]].back();
                indexes[nums[start]].pop_back();
                int second_ind = indexes[nums[end]].back();

                return {first_ind, second_ind};
            }
        }
    }
};
