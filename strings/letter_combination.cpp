/*
Leetcode task from https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Pseudo code:

init hash_map {num: letters}

make_string(map, str, nums, strings):
    for i in len(nums):
        for letter in map[nums[i]]:
            make_string(map, str+letter, nums[i:])
    strings.push_back(str)
    return
*/

class Solution {
public:
    
    unordered_map<char, string > map =
    {{'2', "abc"},
     {'3', "def"},
     {'4', "ghi"},
     {'5', "jkl"},
     {'6', "mno"},
     {'7', "pqrs"},
     {'8', "tuv"},
     {'9', "wxyz"}};
    
    void make_string(unordered_map<char, string> map, string str, 
                     string digits, vector<string> &strings, int str_size) {
        if (str.length() == str_size) {
            strings.push_back(str);
            return;
        }
        
        for (int i = 0; i < digits.length(); ++i) {
            string num_str = map[digits[i]];
            
            for (int j = 0; j < num_str.length(); ++j) {
                make_string(map, str+num_str[j], digits.substr(i+1), strings, str_size);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> strings;
        if (!digits.length()) return strings;
        
        int str_size = digits.length();
        make_string(map, "", digits, strings, str_size);
        return strings;
    }
};

