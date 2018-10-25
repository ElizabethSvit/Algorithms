/*
Leetcode task from https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversalRecursive(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        res = inorderTraversal(root->left);
        res.push_back(root->val);
        vector<int> right_traversal = inorderTraversal(root->right);
        res.insert(res.end(), right_traversal.begin(), right_traversal.end());
        
        return res;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> roots;
        vector<int> res;
        
        while(true) {
            while(root) {
                roots.push(root);
                root = root->left;
            }
            if (roots.empty()) return res;
            TreeNode* node = roots.top();
            roots.pop();
            res.push_back(node->val);
            root = node->right;
        }
        return res;
    }
};

