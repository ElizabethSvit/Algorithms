/*
Leetcode task from https://leetcode.com/problems/binary-tree-level-order-traversal/description/

BFS:

init queue
queue <- root value, level 0
init array of arrays with levels

while queue is not empty
    node, level = queue top
    arrays[level] <- node
    if node -> left 
        queue <- node left, level + 1
    if node -> right
        queue <- node right, level + 1
return arrays
    
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        map<int, vector<int>> res;
        
        while (!q.empty()) {
            pair<TreeNode*, int> node = q.front();
            q.pop();
            
            TreeNode* tree_node = node.first;
            int level = node.second;
            res[level].push_back(tree_node->val);
            
            if (tree_node->left) q.push(make_pair(tree_node->left, level+1));
            if (tree_node->right) q.push(make_pair(tree_node->right, level+1));
        }
        
        vector<vector<int>> res_arr;
        for (const auto &el: res) {
            res_arr.push_back(el.second);
        }
        return res_arr;
    }
};

