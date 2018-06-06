/* Leetcode task https://leetcode.com/problems/add-binary/description/

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"

Solution:

two main patterns:
1. if calculation of a + b + buffer is overflowing (>=2) 
2. if calculation can be divided by 2 => result is 0
*/

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b) {
    int min_size = min(a.size(), b.size());
    int buffer = 0;
    int calc = 0;
    string res = "";
    int i = 0;
    
    while (i < min_size) {
        int a_num = a[a.size() - i - 1] - '0';
        int b_num = b[b.size() - i - 1] - '0';
        calc = a_num + b_num + buffer;
        buffer = (calc >= 2);
        res += to_string(calc % 2);
        i++;
    }
    
    while (i < a.size()) {
        int a_num = a[a.size() - i - 1] - '0';
        
        calc = a_num + buffer;
        buffer = (calc >= 2);
        res += to_string(calc % 2);
        i++;
    }

    while (i < b.size()) {
        int b_num = b[b.size() - i - 1] - '0';
        
        calc = b_num + buffer;
        buffer = (calc >= 2);
        res += to_string(calc % 2);
        i++;
    }
    
    if (buffer) {
        res += '1';
    }
    reverse(res.begin(), res.end());
    return res;
}
