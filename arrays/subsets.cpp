/*
Leetcode task from https://leetcode.com/problems/subsets/description/
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (!nums.size()) return {{}};
        
        vector<vector<int>> empty_vec;
        vector<vector<vector<int>>> res(static_cast<int>(nums.size()+1), empty_vec);
        vector<int> tmp_int;
        res[0].push_back(tmp_int);
        
        for (int i = 1; i < res.size(); ++i) {
            // take all the previous + current
            // take all the previous without current
            res[i] = res[i-1];
            
            for (int j = 0; j < res[i-1].size(); ++j) {
                vector<int> tmp = res[i-1][j];
                tmp.push_back(nums[i-1]);
                res[i].push_back(tmp);
            }
        }
        return res[res.size()-1];
    }
};

