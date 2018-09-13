/*
Leetcode task from https://leetcode.com/problems/maximum-swap/description/

Pseudo code:

convert num to the vector of digits
save last[digit] = index for each digit in num

for each digit in digits (i++):
    for d in 9..digit:
        if last[digit] > i
            swap indicies and return new num
    
*/

class Solution {
public:
    int make_num_from_vec(const vector<int> &digits) {
        int res_num = 0;
        int dec = 1;
        
        for (int i = 0; i < digits.size(); ++i) {
            res_num += (digits[i] * dec);
            dec *= 10;
        }
        return res_num;
    }
    
    int maximumSwap(int num) {
        unordered_map<int, int> last;
        string digits = to_string(num);
        
        for (int i = 0; i < digits.size(); ++i) {
            last[digits[i] - '0'] = i;
        }
        
        for (int i = 0; i < digits.size(); ++i) {
            for (int digit = 9; digit > digits[i] - '0'; --digit) {
                if (last.count(digit) && last[digit] > i) {
                    // cout << i << " " << last[digit] << " " << digit;
                    iter_swap(digits.begin() + i, digits.begin() + last[digit]);
                    return stoi(digits);
                }
            }
        }
        return num;
    }
};

