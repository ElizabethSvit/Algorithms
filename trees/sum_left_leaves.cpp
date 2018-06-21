/*
Leetcode task from https://leetcode.com/problems/sum-of-left-leaves/description/


Pseudo code (slower):

int sum(root, left):
    if (!root) return 0
    if (!root->left && !root->right):
        if (left) return root->val
        else return 0
    return sum(root->left, true) + sum(root->right, false)
    
Pseudo code (faster):

int sum(root):
    if (!root) return 0
    
    TreeNode* left_node = root->left
    int left_sum = 0
    
    if (left_node):
        if (!left_node->left && !left_node->right):
            left_sum = left_node->val
        else left_sum = sum(left_node->left)
    
    return left_sum + sum(left_node->right)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    int sum_helper(TreeNode* root, bool left) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            if (left) return root->val;
            else return 0;
        }
        return sum_helper(root->left, true) + sum_helper(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return sum_helper(root, false);
        
    }
};

