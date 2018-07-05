/*
Leetcode task from https://leetcode.com/problems/multiply-strings/description/

Pseudo code

init nums_arr[110]

for every num in num1:
    for every num in nums2:
        curr_prod = multiply(nums1[i], nums2[j])
        nums_arr[i+j] = (nums_arr[i+j] + (curr_prod % 10) + curr_prod_mem + curr_arr_mem) % 10
        curr_prod_mem = curr_prod / 10
        curr_arr_mem = nums_arr[i+j] / 10

go thru nums_arr inversed:
    str_res += nums_arr[i]

return str_res
        
*/

class Solution {
public:
    
    int multiply_simple(char num1, char num2) {
        int n1 = num1 - '0';
        int n2 = num2 - '0';
        return n1 * n2;
    }
    
    string multiply(string num1, string num2) {
        int curr_prod = 0;
        int arr_prod = 0;
        int curr_prod_mem = 0;
        int curr_arr_mem = 0;
        
        vector<int> nums_arr(110, 0);
        string str_res = "";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
                
        for (int i = 0; i < num2.length(); ++i) {
            for (int j = 0; j < num1.length(); ++j) {
                curr_prod = multiply_simple(num1[j], num2[i]);
                arr_prod = nums_arr[i+j] + (curr_prod % 10) + curr_prod_mem + curr_arr_mem;
                nums_arr[i+j] = arr_prod % 10;
                
                curr_prod_mem = curr_prod / 10;
                curr_arr_mem = arr_prod / 10;
            }
        }

        int max_index = num1.length() + num2.length() - 1;
        if (nums_arr[max_index + 1] != 0) max_index++;
        
        for (int i = max_index - 1; i >= 0; --i) {
            str_res += (nums_arr[i] + '0');
        }
        
        return str_res;
    }
};

