/*
Leetcode task from https://leetcode.com/problems/validate-binary-search-tree/description/

Pseudo code:

is_valid(root, left_bound, right_bound)
    if !root return true
    if root value between left_bound and right_bound:
        return is_valid(root->left, 0, root value) and is_valid(root->right, root value, right_bound)
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
    
    bool is_valid(TreeNode* root, int left_bound, int right_bound) {
        if (!root) return true;
        if (left_bound <= root->val && root->val <= right_bound) {
            if (root->val == INT_MIN && root->left) return false;
            if (root->val == INT_MAX && root->right) return false;
            return is_valid(root->left, left_bound, root->val-1) && is_valid(root->right, root->val+1, right_bound);
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return is_valid(root, INT_MIN, INT_MAX);
    }
};

