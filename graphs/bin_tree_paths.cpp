/*
Leetcode task from https://leetcode.com/problems/binary-tree-paths/description/
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

/*

     1
   /   \
  2     3
 /  \
6    5
  
curr_path: 1 
curr_path: 1 -> 2 (at least one child);  curr_path: 1 -> 3 (no children)
curr_path: 1 -> 2 -> 6 (no children); curr_path: 1 -> 2 -> 5 (no children);

Pseudo code

Recursively start from root 
add root->key to curr_path

if root doesn't have children:
    add curr_path to res_paths
    return
if root->left:
    go recursively to left child
if root->right:
    go recursively to right child


*/
class Solution {
public:
    
    void recur_traversal(TreeNode* root, vector<string> &res_paths, string &curr_path) {
        cout << curr_path << endl;
        if (!root) {
            return;
        }
        
        if (!root->left && !root->right) {
            res_paths.push_back(curr_path + to_string(root -> val));
            return;
        }
        
        if (root -> left) {
            string next_path = curr_path + to_string(root -> val) + "->";
            recur_traversal(root -> left, res_paths, next_path);
        }
        if (root -> right) {
            string next_path = curr_path + to_string(root -> val) + "->";
            recur_traversal(root -> right, res_paths, next_path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res_paths;
        string empty_str = "";
        recur_traversal(root, res_paths, empty_str);
        return res_paths;
    }
};
