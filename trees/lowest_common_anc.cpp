/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
Leetcode task from https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

Pseudo code (recursion)

lowest_common_anc(root, p, q):
    if (!root || !p || !q) return null
    
    if (root == p || root == q) return root
    
    TreeNode left = lowest_common_anc(root->left, p, q)
    TreeNode right = lowest_common_anc(root->right, p, q)
    
    if (left && right) return root
    return left ? left : right;
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        
        if (root == p || root == q) return root;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);
        
        if (left && right) return root;
        return left ? left : right;
    }
};

