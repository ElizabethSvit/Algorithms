/*
Leetcode task from https://leetcode.com/problems/powx-n/description/

pow(x, n)
    if n == 0
        return 1
    if n < 0
        x = 1 / x
        // modification for overflow cases
        return (n % 2) ? x * pow(x * x, -(n / 2)) : pow(x * x, -(n / 2))
    return (n % 2) ? x * pow(x * x, n / 2) : pow(x * x, n / 2)
*/

class Solution {
public:
    
    double myPow(double x, int n) {
        if (!n) return 1;
        if (n < 0) {
            x = 1 / x;
            return (n % 2 == 0) ? myPow(x * x, -(n / 2)) : x * myPow(x * x, -(n / 2));
        }
        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
        
    }
};

