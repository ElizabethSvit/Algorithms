/*
Leetcode task from https://leetcode.com/problems/hamming-distance/description/

Pseudo code:

x_bit = x & 1
y_bit = y & 1
counter = 0

while (x && y):
    counter += (x_bit & y_bit)
    x_bit = x >> 1
    y_bit = y >> 1
return counter
    
*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int x_bit, y_bit;
        int counter = 0;
        
        while (x || y) {
            x_bit = (x & 1);
            y_bit = (y & 1);
            counter += (x_bit ^ y_bit);
            x = x >> 1;
            y = y >> 1;
        }
        return counter;
    }
};

