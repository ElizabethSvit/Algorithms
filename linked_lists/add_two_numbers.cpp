/*
Leetcode task from https://leetcode.com/problems/add-two-numbers/description/

Pseudo code

go thru digits of first and second
    sum up both values + carry and take module 10
    put dec part of the sum to carry
if carry is not 0 -> add it to one new node

+ take care of different lengths of linked lists
    
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    
    int length(ListNode* l) {
        int len = 0;
        while (l) {
            len++;
            l = l->next;
        }
        return len;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head_res = new ListNode(0);
        ListNode* res = head_res;
        int sum = 0;
        int carry = 0;
        
        int l1_len = length(l1);
        int l2_len = length(l2);
        
        while (l1 && l2) {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            res->val = sum % 10;
            
            if (l1->next || l2->next || carry) {
                ListNode* node = new ListNode(0);
                res->next = node;
            }
            l1 = l1->next;
            l2 = l2->next;
            res = res->next;
        }
        
        if (l1_len < l2_len) {
            while (l2) {
                sum = l2->val + carry;
                carry = sum / 10;
                res->val = sum % 10;

                if (l2->next || carry) {
                    ListNode* node = new ListNode(0);
                    res->next = node;
                }
                l2 = l2->next;
                res = res->next;
            }
        }
        
        if (l2_len < l1_len) {
            while (l1) {
                sum = l1->val + carry;
                carry = sum / 10;
                res->val = sum % 10;

                if (l1->next || carry) {
                    ListNode* node = new ListNode(0);
                    res->next = node;
                }
                l1 = l1->next;
                res = res->next;
            }
        }
        
        if (carry) {
            res->val = carry;
            // res = res->next;
        }
        return head_res;
    }
};

