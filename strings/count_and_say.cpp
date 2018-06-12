/*
Leetcode task from https://leetcode.com/problems/count-and-say/description/

1.     1
2.     11
3.     21
4.     1211
5.     111221

6.     312211
7.     13112221
8.     1113213211


Pseudo code:

bruteforce solution

apply rule for every iteration until iteration number is n 
rule: for every num count how many consequtive and add cunter and num

prev_str = string
for i in 1..n:
    curr_str = ""
    for i in len(prev_str):
        counter = 0
        while (prev_str[i] == prev_str[i+1]):
            counter++
            i++
        curr_str += counter
        curr_str += str[i-1]
    prev_str = curr_str
return prev_str

*/

class Solution {
public:
    string countAndSay(int n) {        
        string prev_str = "1";
        string curr_str = "";
        int counter = 0;
        int curr_num;
        
        for (int i = 0; i < n - 1; ++i) {
            curr_str = "";
            for (int i = 0; i < prev_str.size(); ++i) {
                counter = 1;
                int curr_num = prev_str[i];
                while (i < prev_str.size() - 1 && prev_str[i] == prev_str[i+1]) {
                    counter++;
                    i++;
                }
                curr_str += to_string(counter);
                curr_str += curr_num;
            }
            prev_str = curr_str;
        }
        
        return prev_str;
    }
};

