/*
Leetcode task from https://leetcode.com/problems/clone-graph/description/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    map<int, UndirectedGraphNode*> nodes;
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        if (nodes[node->label]) return nodes[node->label];
        
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        nodes[node->label] = newNode;
        
        for (int i = 0; i < node->neighbors.size(); ++i) {
            newNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
        }
        return newNode;
    }
};

