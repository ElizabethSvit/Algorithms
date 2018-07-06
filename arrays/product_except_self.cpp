/*
Leetcode task from https://leetcode.com/problems/product-of-array-except-self/description/

Pseudo code

prod = 1
rev_prod = 1
res_prod[n]

go from start+1 to end 
    prod *= nums[i-1]
    res_prod[i] = prod
go from end-1 to start
    rev_prod *= nums[n-i]
    res_prod[i] *= rev_prod

return res_prod
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> total_prod(nums.size(), 0);
        int prod = 1;
        int rev_prod = 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            total_prod[i] = prod;
            prod *= nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            total_prod[i] *= rev_prod;
            rev_prod *= nums[i];
        }
        return total_prod;
    }
};

