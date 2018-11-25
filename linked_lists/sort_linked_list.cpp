/*
Leetcode task from https://leetcode.com/problems/sort-list/submissions/

Commented solution is very slow, but mine :)
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
//     ListNode* sortList(ListNode* head) {
//         if (!head || !head->next) return head;
        
//         ListNode* res_head = new ListNode(head->val);
//         head = head -> next;
//         while (head) {
//             ListNode* tmp = new ListNode(head->val);
//             if (res_head->val > head->val) {
//                 tmp->next = res_head;
//                 res_head = tmp;
//             } else {
//                 ListNode* tmp_res_head = res_head;
//                 while (tmp_res_head->next && tmp_res_head->next->val <= head->val) 
//                     tmp_res_head = tmp_res_head->next;
//                 if (tmp_res_head->next) tmp->next = tmp_res_head->next;
//                 tmp_res_head->next = tmp;
//             }
//             head = head->next;
//         }
//         return res_head;
//     }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* head_res = res;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                res->next = l1;
                res = res->next;
                l1 = l1->next;
            } else {
                res->next = l2;
                res = res->next;
                l2 = l2->next;
            }
        }
        
        if (l1 || l2) {
            res->next = l1 ? l1 : l2;
        }
        return head_res->next;
    }
    
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while (fast && fast->next) {
            prev = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        prev->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        return mergeLists(l1, l2);
        
    }
};

