/*

Leetcode task from https://leetcode.com/problems/valid-palindrome/description/

Plan

Go thru the array and make a string with only alphanumeric characters.
Reverse string and compare it with the original one.
*/

#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        string forward;
        string backward;
        
        for (char ch: s) {
            ch = tolower(ch);
            if (isdigit(ch) || isalpha(ch)) {
                forward += ch;
            }
        }
        
        backward = forward;
        reverse(backward.begin(), backward.end());
        return forward == backward;
    }
};
