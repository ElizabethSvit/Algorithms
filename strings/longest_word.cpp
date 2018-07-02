/*
 GetAhead Google program task
 
 Given a 4X4 grid of letters and a dictionary, find the longest word from the dictionary that can be formed in the grid.
 The rules for forming a word are:
 - Start at any position on the board
 - Move in any of the up to 8 directions to choose another letter
 - Repeat
 - Words must be at least 3 characters long
 - You cannot reuse a letter in a given position in the same word
 
 You are given a dictionary, with helper functions like isWord() to check if a word is valid and isPrefix() to check if a string is a prefix of some valid word.
 
 Test Cases
 Note that there may be other valid answers.
 
 For the grid below, the longest word is EMBOIL:
 F X I E
 A M L O
 E W B X
 A S T U
 
 Pseudo code:
 
 max_len = 0
 
 longest_word(prefix, grid, i, j, max_len)
    if prefix.isWord() && prefix.length() >= 3
        max_len = max(max_len, prefix.length())
    if prefix.isPrefix()
        if dir1 is not out of boundaries
            longest_word(prefix+grid[dir1], grid, i+1, j+1, max_len)
        ... for other 7 directions
    return
 
 find_longest_word(grid)
    max_lengths = []
    for cell in grid
        if !max_lengths[cell]
            longest_word(cell, grid)
            max_lengths.push(cell)
    return max_len
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> dictionary = {"fame", "google", "emboil"};
int max_len = 0;

bool isWord(string word) {
    return dictionary.find(word) != dictionary.end();
}

bool isPrefix(string word) {
    for (auto str: dictionary) {
        if (str.compare( 0, word.size(), word ) == 0) return true;
    }
    return false;
}

void longest_word(string prefix, vector<vector<char>> &grid, int i, int j) {
    if (isWord(prefix) && static_cast<int>(prefix.length()) >= 3) {
        max_len = max(max_len, static_cast<int>(prefix.length()));
        return;
    }
    if (isPrefix(prefix)) {
        char temp = grid[i][j];
        grid[i][j] = '\0';
        if (i+1 < grid.size() && j+1 < grid[i].size()) {
            longest_word(prefix+grid[i+1][j+1], grid, i+1, j+1);
        }
        if (i+1 < grid.size() && j-1 >= 0) {
            longest_word(prefix+grid[i+1][j-1], grid, i+1, j-1);
        }
        if (i-1 >= 0 && j+1 < grid[i].size()) {
            longest_word(prefix+grid[i-1][j+1], grid, i-1, j+1);
        }
        if (i-1 >= 0 && j-1 >= 0) {
            longest_word(prefix+grid[i-1][j-1], grid, i-1, j-1);
        }
        if (j+1 < grid[i].size()) {
            longest_word(prefix+grid[i][j+1], grid, i, j+1);
        }
        if (i+1 < grid.size()) {
            longest_word(prefix+grid[i+1][j], grid, i+1, j);
        }
        if (i-1 >= 0) {
            longest_word(prefix+grid[i-1][j], grid, i-1, j);
        }
        if (j-1 >= 0) {
            longest_word(prefix+grid[i][j-1], grid, i, j-1);
        }
        grid[i][j] = temp;
    }
    return;
}

int find_longest_word(vector<vector<char>> &grid) {
    set<pair<int,int>> max_lengths;
    
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (max_lengths.find(make_pair(i,j)) == max_lengths.end()) {
                longest_word(string(1, grid[i][j]), grid, i, j);
                max_lengths.insert(make_pair(i,j));
            }
        }
    }
    return max_len;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '\0'));
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            cin >> grid[i][j];
            grid[i][j] = tolower(grid[i][j]);
        }
    }
    cout << find_longest_word(grid);
    return 0;
}


