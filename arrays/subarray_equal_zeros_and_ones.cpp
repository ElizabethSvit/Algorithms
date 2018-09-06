/*
Leetcode task from https://leetcode.com/problems/contiguous-array/description/

Pseudo code:

int count = 0
max_length = 0

for (i in nums.size):
    nums[i] == 0 ? count-- : count++
    if (same_count[count]) {
        max_length = max(max_length, i - same_count[count])
    }
    
return max_length
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> same_count;
        same_count[0] = -1;
        int count = 0;
        int max_length = 0;

        for (int i = 0; i < nums.size(); ++i) {
            
            nums[i] == 0 ? count-- : count++;
            if (same_count.find(count) != same_count.end()) {
                max_length = max(max_length, i - same_count[count]);
            } else {
                same_count[count] = i;
            }
        }
        return max_length;
    }
};

