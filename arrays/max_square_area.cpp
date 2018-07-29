/*
Leetcode task from https://leetcode.com/problems/maximal-square/description/

Pseudo code:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0


find a square for each cell:

dfs(matrix, i1, j1, i2, j2, cur area):
    check the boundaries of matrix
    
    for j in j2 - j1
        if matrix[i1][j] is 0:
            return cur area
    for i in i2 - i1
        if matrix[i][j2] is 0:
            return cur area
    dfs(matrix, i1+1, j1, i2, j2+1, updated area)
    
go over each cell:
    // consider each cell as a left upper edge of a square
    if area of square > max
        max = new square
*/

class Solution {
public:
    
    int dfs(vector<vector<char>>& matrix, int i, int j, int down, int right, int cur_area) {
        if (down >= matrix.size() || right >= matrix[down].size()) {
            return cur_area;
        }
        
        for (int cur_j = j; cur_j <= right; ++cur_j) {
            if (matrix[down][cur_j] == '0') return cur_area;
        }
        
        for (int cur_i = i; cur_i <= down; ++cur_i) {
            if (matrix[cur_i][right] == '0') return cur_area;
        }
        down++;
        right++;
        return dfs(matrix, i, j, down, right, pow(right-j, 2));
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int max_area = 0;
        int cur_area = 0;
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == '1') {
                    
                    cur_area = dfs(matrix, i, j, i+1, j+1, 1);
                    if (cur_area > max_area) max_area = cur_area;
                }
            }
        }
        return max_area;
    }
};

