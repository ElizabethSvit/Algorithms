/*
Leetcode task from https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

    1
   /  \
  2    3
 / \   / \
4   5  6  7
/\  /\
9 0 0 9 

Pseudo code:

connect(root)
    head <- null
    prev <- null
    cur <- root
    
    // until levels are over
    while (cur) 
        while (cur)
            if cur->left 
                if prev (already not left most)
                    prev->next = cur->left
                else
                    head = cur->left
                prev = cur->left
                
            same for right child if exists
            cur = cur->next
        // go to the next level
        cur = head
        head = null
        prev = null
        
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    
    void connect(TreeLinkNode *root) {
        TreeLinkNode* head = NULL;
        TreeLinkNode* prev = NULL;
        TreeLinkNode* cur = root;
        
        while (cur) {
            while (cur) {
                if (cur->left) {
                    if (prev) prev->next = cur->left;
                    else head = cur->left;
                    prev = cur->left;
                }
                
                if (cur->right) {
                    if (prev) prev->next = cur->right;
                    else head = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            cur = head;
            head = NULL;
            prev = NULL;
        }
    }
};

