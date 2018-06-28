/*
Leetcode task from https://leetcode.com/problems/number-of-islands/description/

Pseudo code (BFS):

BFS(cell, gris, visited):
    init queue
    queue.push(cell)
    
    while (!queue.empty()):
        node = queue.front()
        queue.pop_front()
        if (node[0]-1 >= 0) visited[{[node[0]-1][node[1]]}] = true
        if (node[0]+1 < grid[0].size()) visited[{[node[0]+1][node[1]]}] = true
        if (node[1]-1 >= 0) visited[{[node[0]][node[1]-1]}] = true
        if (node[1]+1 < grid.size()) visited[{[node[0]][node[1]+1]}] = true
    
        
        
init map visited
init islands = 0

for cell in grid:   
    if visited.find(cell) == visited.end():
        visited[cell] = true
        BFS(cell, grid, visited)
        islands ++
return islands
*/

class Solution {
public:
    
    void bfs(int i, int j, const vector<vector<char>> &grid, 
             map<vector<int>, bool> &visited) {
        queue<vector<int>> q;
        q.push({i, j});
        
        while (!q.empty()) {
            vector<int> node = q.front();
            q.pop();
            if (node[0]-1 >= 0 && visited.find({node[0]-1,node[1]}) == visited.end()
                && grid[node[0]-1][node[1]] == '1') {
                visited[{node[0]-1,node[1]}] = true;
                q.push({node[0]-1,node[1]});
            }
            
            if (node[0]+1 < grid.size() && visited.find({node[0]+1,node[1]}) == visited.end()
                && grid[node[0]+1][node[1]] == '1') {
                visited[{node[0]+1,node[1]}] = true;
                q.push({node[0]+1,node[1]});
            }
            
            if (node[1]-1 >= 0 && visited.find({node[0],node[1]-1}) == visited.end()
                && grid[node[0]][node[1]-1] == '1') {
                visited[{node[0],node[1]-1}] = true;
                q.push({node[0],node[1]-1});
            }
            
            if (node[1]+1 < grid[0].size() && visited.find({node[0],node[1]+1}) == visited.end()
                && grid[node[0]][node[1]+1] == '1') {
                visited[{node[0],node[1]+1}] = true;
                q.push({node[0],node[1]+1});
            }
        }
    }
    
    int myNumIslands(vector<vector<char>>& grid) {
        int islands = 0;
        map<vector<int>, bool> visited;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (visited.find({i,j}) == visited.end() && grid[i][j] == '1') {
                    visited[{i,j}] = true;
                    bfs(i, j, grid, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    // easiest and fastest solution
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[i].size() - 1 || grid[i][j] != '1') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};

