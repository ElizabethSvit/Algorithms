/*
Leetcode task from https://leetcode.com/problems/diameter-of-binary-tree/description/

Pseudo code:

init max_diam

int height(root):
    if (!root) return 0
    int left_height = height(root->left)
    int right_height = height(root->right)
    max_diam = max(left_height + right_height, max_diam)
    return max(left_height, right_height) + 1
    
int max_diam(root):
    height(root)
    return max_diam
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
    int max_diam;
    
    int height(TreeNode* root) {
        if (!root) return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);
        max_diam = max(left_height + right_height, max_diam);
        return max(left_height, right_height) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        max_diam = 0;
        
        height(root);
        return max_diam;
    }
};

