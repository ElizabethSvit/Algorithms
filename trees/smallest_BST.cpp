/*
Leetcode task from https://leetcode.com/problems/binary-search-tree-iterator/description/

Inorder traversal gives sorted array. 

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<int> sorted_tree;
public:
    
    void dfs(TreeNode *root) {
        if (!root) return;

        dfs(root->right);
        sorted_tree.push(root->val);
        dfs(root->left);
    }
    
    BSTIterator(TreeNode *root) {
        dfs(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !sorted_tree.empty();
    }

    /** @return the next smallest number */
    int next() {
        int tmp = sorted_tree.top();
        sorted_tree.pop();
        return tmp;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

