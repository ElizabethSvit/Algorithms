/*
Leetcode task from https://leetcode.com/problems/decode-ways/description/

Pseudo code (recursion):

numDecoding(string s, int n):
    if n == 0 || n == 1:
        return 1
        
    count = 0
    if s[n-1] > '0':
        count = numDecoding(s, n-1)
    if s[n-2] == '1' || s[n-2] == '2' && s[n-1] < '7':
        count += numDecoding(s, n-2)
    return count
    
Pseudo code (DP):

numDecoding(string s):
    n = s.length()
    vector<int> ways(n+1, 0)
    ways[0] = 1
    ways[1] = 1
    for i in 2..n:
        if s[i] > '0':
            ways[i] = ways[i-1]
        if s[i-1] == '1' || s[i-1] == '2' && s[i-1] < '7':
            ways[i] += ways[i-2]
    return ways[n]
*/

class Solution {
public:
    int decode_DP(string s) {
        int n = s.length();
        vector<int> ways(n+1, 0);
        ways[0] = 1;
        ways[1] = 1;
                
        for (int i = 2; i <= n; ++i) {
            if (s[i-1] > '0') ways[i] = ways[i-1];
            if (s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7') ways[i] += ways[i-2];
        }
        return ways[n];
    }
    
    int decode_recursion(string s, int n) {
        if (n == 0 || n == 1) return 1;
        
        int count = 0;
        if (s[n-1] > '0') count = decode_recursion(s, n-1);
        if (s[n-2] == '1' || s[n-2] == '2' && s[n-1] < '7') count += decode_recursion(s, n-2);
        return count;
    }
    
    int numDecodings(string s) {
        if (s.length() && s[0] == '0' || !s.length()) return 0;
        if (s.length() == 1) return 1;
        return decode_DP(s);
    }
};

