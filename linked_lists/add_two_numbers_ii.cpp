/*
Leetcode task from https://leetcode.com/problems/add-two-numbers-ii/description/

Pseudo code:

ListNode add_numbers(l1, l2)
    if !l1->next || !l2->next
        node = new Node(l1->val + l2->val)
        return node
    res->next = add_numbers(l1->next, l2->next)
    sum = l1 val + l2 val + carry
    
    node = new Node(sum % 10)
    carry = sum / 10
    return node
    
add_lists:
    count lengths of lists
    pad with zeros the smallest list
    add numbers
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
    
    int carry;
    ListNode* res;
    
    int length(ListNode* l) {
        int len = 0;
        while (l) {
            len++;
            l=l->next;
        }
        return len;
    }
    
    ListNode* insert_before(ListNode* l, int data) {
        ListNode* node = new ListNode(data);
        if (l) {
            node->next = l;
        }
        return node;
    }
    
    ListNode* padding(ListNode* l, int pad_len) {
        ListNode* head = l;
        for (int i = 0; i < pad_len; ++i) {
;            head = insert_before(head, 0);
        }
        return head;
    }
    
    void add_numbers_helper(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            carry = 0;
            return;
        }
        
        add_numbers_helper(l1->next, l2->next);
        int sum = l1->val + l2->val + carry;
        res = insert_before(res, sum % 10);
        carry = sum / 10;
        return; 
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1_len = length(l1);
        int l2_len = length(l2);
        if (l1_len < l2_len) {
            l1 = padding(l1, l2_len - l1_len);
        } else if (l1_len > l2_len) {
            l2 = padding(l2, l1_len - l2_len);
        }
        
        add_numbers_helper(l1, l2);
        if (carry) {
            res = insert_before(res, carry);
        }
        return res;
    }
};

