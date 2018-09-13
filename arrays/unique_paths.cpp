/*
Leetcode task from https://leetcode.com/problems/unique-paths/description/

make a 2d array

for every cell the num of possibilities is cell[i-1][j] + cell[i][j-1]
return cell[n][n]
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!i || !j) paths[i][j] = 1;
                else paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[n-1][m-1];
    }
};

