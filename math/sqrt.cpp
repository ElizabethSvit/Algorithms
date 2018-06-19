/*
Leetcode task from https://leetcode.com/problems/sqrtx/description/

Obvious solution:

while i * i < x:
    i++
return i - 1

Binary search solution 
(left boundary is x/i, right boundary is i; finally x/i and i meet => x = i*i):

init i = x
while i * i > x:
    i = (i + x/i) / 2
return i
    
*/

class Solution {
public:
    int mySqrt(int x) {
        long i = x;
        long a = x; // reduce the runtime
        while (i * i > a) {
            i = (i + a/i) / 2;
        }
        return i;
    }
};

