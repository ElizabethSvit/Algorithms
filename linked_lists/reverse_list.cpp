/*
Leetcode task from https://leetcode.com/problems/reverse-linked-list/description/
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
    
    /*
    Iterative solution

    1->2->NULL

    NULL <- 1 ; next_node = 2; head = 1
    NULL <- 1 <- 2; next_node = NULL; head = 2
    NULL <- 1 <- 2; stop

    Pseudo code:

    prev_node = NULL
    head = first node

    while (head != NULL):
        next_node = head -> next
        head -> next = prev_node
        prev_node = head
        head = next_node

    return prev_node
    */
    
    ListNode* reverseListIter(ListNode* head) {
        ListNode* prev_node = nullptr;
        ListNode* next_node;
        
        while (head != nullptr) {
            next_node = head -> next;
            head -> next = prev_node;
            prev_node = head;
            head = next_node;
        }
        return prev_node;
    }
    
    /*
    Recursive solution
    
    1->2->3->NULL
    
    stop at 3
    tail: 3, head: 2
    3 -> 2, return 2
    tail: 2, head: 1
    3 -> 2 -> 1

    Pseudo code:

    reverse_list(head, prev_node) {
        if (head -> next == nullptr or head == nullptr):
            return head

        reversed_tail = reverse_list(head -> next)
        head -> next -> next = head
        head -> next = nullptr
        
        return reversed_tail
    }
    */
    
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        
        ListNode *reversed_tail = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return reversed_tail;
    }
};
