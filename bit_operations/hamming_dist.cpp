/*
Leetcode task from https://leetcode.com/problems/hamming-distance/description/
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int counter = 0;
        while (max(x,y)) {
            counter += (x & 1) ^ (y & 1);
            x = x >> 1;
            y = y >> 1;
        }
        return counter;
    }
};

