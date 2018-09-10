/*
Leetcode task from https://leetcode.com/problems/h-index/description/

Pseudo code:

sort in descending order
for i in citations.size:
    if (i <= citations[i])
        h_index = i
return h_index
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() < 2) {
            if (citations.size() == 1) {
                return citations[0] > 0;
            }
            return 0;
        }
        
        sort(citations.begin(), citations.end(), greater<int>());
        int h_index = 0;
        
        for (int i = 0; i < citations.size(); ++i) {
            // cout << i + 1 << citations[i] << endl;
            if ((i + 1) <= citations[i]) {
                    h_index = (i + 1);
            }
        }
        return h_index;
    }
};

