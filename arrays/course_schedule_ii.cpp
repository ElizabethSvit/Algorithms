/*
Leetcode task from https://leetcode.com/problems/course-schedule-ii/description/

Pseudo code:

make adjacency matrix for all pairs

put nodes in the queue and in degrees
take from queue and put all the neighbours in queue
when in degree is 0 put in the result

*/

class Solution {
public:
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegrees(numCourses, 0);
        
        queue<int> nodes;
        vector<int> result;
        
        // fill the graph and indegrees
        for (const auto &pair: prerequisites) {
            graph[pair.second].push_back(pair.first);
            ++indegrees[pair.first];
        }
        
        // fill up the queue with 0 indegrees
        for (int i = 0; i < indegrees.size(); ++i) {
            if (indegrees[i] == 0) nodes.push(i);
        }
        
        int visited_nodes = 0;
        
        while (!nodes.empty()) {
            visited_nodes++;
            int node = nodes.front();
            nodes.pop();
            result.push_back(node);
            
            for (int neighbour: graph[node]) {
                 
                indegrees[neighbour]--;
                if (indegrees[neighbour] == 0) nodes.push(neighbour);
            }
        }
        
        return numCourses == visited_nodes ? result : vector<int>();
    }
};

