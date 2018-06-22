/*
Leetcode task from https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

Pseudo code:

init avg_levels = [[]]
init level_num = 0

avg_levels_helper(root, avg_levels, level_num):
    if (!root) return
    
    avg_levels[level_num].push_back(root->val)
    avg_levels_helper(root->left, avg_levels, level_num)
    avg_levels_helper(root->right, avg_levels, level_num)
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
    //BFS
    void avg_levels_bfs(TreeNode* root, map<int, vector<int>> &avg_levels) {
        if (!root) return;
        
        queue<pair<TreeNode*, int>> nodes;
        nodes.push({root, 0});
        pair<TreeNode*, int> p;
        
        while (!nodes.empty()) {
            p = nodes.front();
            nodes.pop();
            // cout << nodes.size() << endl;
            avg_levels[p.second].push_back(p.first->val);
            if (p.first->left) nodes.push({p.first->left, p.second+1});
            if (p.first->right) nodes.push({p.first->right, p.second+1});
        }
    }
    
    // DFS
    void avg_levels_dfs(TreeNode* root, map<int, vector<int>> &avg_levels, int level_num) {
        if (!root) return;
        
        avg_levels[level_num].push_back(root->val);
        avg_levels_dfs(root->left, avg_levels, level_num+1);
        avg_levels_dfs(root->right, avg_levels, level_num+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        map<int, vector<int>> avg_levels;
        avg_levels_bfs(root, avg_levels);
        
        vector<double> values;
        for (auto pair: avg_levels) {
            vector<int> value_arr = pair.second;
            values.push_back(accumulate( value_arr.begin(), value_arr.end(), 0.0)/value_arr.size() );
        }
        return values;
    }
};

