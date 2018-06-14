/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*

Leetcode task from https://leetcode.com/problems/palindrome-linked-list/description/

Pseudo code (space O(n)):

go thru list and save to array
check if array is palindrome

Pseudo code (space O(1)):



*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> list_values;
        while (head) {
            list_values.push_back(head -> val);
            head = head -> next;
        }
        
        int left = 0;
        int right = list_values.size() - 1;
        
        while (left < right) {
            if (list_values[left] != list_values[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

