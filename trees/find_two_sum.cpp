/*
Leetcode task from https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

Pseudo code:

find_target_helper(root, k, set):
    if (!root) return false
    if (set.find(k-root->val) != set.end()) return true
    set.insert(root->val)
    return find_target_helper(root->left,k,set) ||
        find_target_helper(root->right,k,set)
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
    
    bool find_target_helper(TreeNode* root, int k, set<int> &values) {
        if (!root) return false;
        if (values.find(k-root->val) != values.end()) return true;
        values.insert(root->val);
        return find_target_helper(root->left,k,values) ||
            find_target_helper(root->right,k,values);
    }
    
    bool findTarget(TreeNode* root, int k) {
        set<int> values;
        return find_target_helper(root, k, values);
    }
};

