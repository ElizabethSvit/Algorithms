/*

Leetcode task from https://leetcode.com/problems/word-search/description/

Pseudo code

exist_helper(board, i, j, word, visited):
    if (!word.size()) return true
    if !visited[i][j]: 
        if (word[0] == board[i][j]):
            visited[i][j] = true
            return exist_helper(board, i-1, j, word[1:], visited) ||
                    ... 4 cases in total
*/

class Solution {
public:
    
    bool exist_helper(vector<vector<char>>& board, int i, int j, 
                      string word, vector<vector<bool>> &visited) {
        if (!word.size()) return true;
        bool res = false;
        if (i >= 0 && i < board.size() && j >= 0 && j < board[i].size() && !visited[i][j]) {
            if (word[0] == board[i][j]) {
                visited[i][j] = true;
                res = exist_helper(board, i-1, j, word.substr(1, word.size()), visited) ||
                    exist_helper(board, i, j-1, word.substr(1, word.size()), visited) ||
                    exist_helper(board, i+1, j, word.substr(1, word.size()), visited) ||
                    exist_helper(board, i, j+1, word.substr(1, word.size()), visited);
                visited[i][j] = false;
            }
        }
        return res;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size() || !board[0].size()) return false;
        if (!word.size()) return true;
        
        bool res = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (word[0] == board[i][j]) {
                    vector<vector<bool>> visited (board.size(), vector<bool> (board[0].size(), false));
                    res = res || exist_helper(board, i, j, word, visited);
                }
            }
        }
        return res;
    }
};

