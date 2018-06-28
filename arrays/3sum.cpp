/*
Leetcode task from https://leetcode.com/problems/3sum/description/

Pseudo code (bruteforce):

sort array

init vector<vector<int>> res_triples
for i in 1..n:
    first_el = arr[i]
    sec_el = arr[i+1]
    // search for third element using binsearch
    if binsearch(-(first_el+sec_el)):   
        res_triples.push_back(first_el, sec_el, -(first_el+sec_el))
return res_triples

Optimal solution beneath.
    
*/

class Solution {
public:
    
    vector<vector<int>> find_pair(vector<int> nums, int i) {
        int k = nums[i];
        int left = i+1;
        int right = nums.size() - 1;
        vector<vector<int>> pairs;
        set<int> sec_el;
        
        while (left < right) {
            if (nums[left] + nums[right] < -k) left++;
            else if (nums[left] + nums[right] > -k) right--;
            else {
                if (sec_el.find(nums[left]) == sec_el.end()) {
                    sec_el.insert(nums[left]);
                    pairs.push_back({nums[left], nums[right]});
                }
                left++;
                right--;
            }
        }
        return pairs;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res_triples;
        if (nums.size() < 3) return res_triples;
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> pairs;
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            pairs = find_pair(nums, i);
            while (pairs.size()) {
                res_triples.push_back({nums[i], pairs[pairs.size()-1][0], pairs[pairs.size()-1][1]});
                pairs.pop_back();
            }
            
        }
        return res_triples;
    }
};

