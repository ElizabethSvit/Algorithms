/*
Leetcode task from https://leetcode.com/problems/subsets-ii/description/

Pseudo code

sort nums

init subsets
for i in 0..n:
    if [] or last value in subset != current num
        add subset from subsets
    add subset + current num to subsets
    
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (!nums.size()) return {{}};
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> subsets;
        subsets.push_back({});
        
        for (int i = 0; i < n; ++i) {
            vector<vector<int>> temp_subsets;
            for (vector<int> subset: subsets) {
                if (!subset.size() || subset[subset.size()-1] != nums[i]) {
                    temp_subsets.push_back(subset);
                }
                subset.push_back(nums[i]);
                temp_subsets.push_back(subset);
            }
            subsets = temp_subsets;
        }
        return subsets;
    }
};

