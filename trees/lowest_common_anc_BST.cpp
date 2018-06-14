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
Leetcode task from https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

Plan (recursive)

lowest_common_anc(root, p, q):
    int rv
    int pv
    int qv
    
    if (rv == pv || rv == qv) return root
    if (rv < pv && rv < qv) return lowest_common_anc(root->right, p, q)
    if (rv > pv && rv > qv) return lowest_common_anc(root->left, p , q)
    return root

*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int rv = root -> val;
        int pv = p -> val;
        int qv = q -> val;
        
        if (rv == pv || rv == qv) return root;
        if (rv < pv && rv < qv) return lowestCommonAncestor(root -> right, p, q);
        if (rv > pv && rv > qv) return lowestCommonAncestor(root -> left, p, q);
        return root;
    }
};

