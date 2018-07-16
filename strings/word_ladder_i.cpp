/*
Leetcode task from https://leetcode.com/problems/word-ladder/description/

Pseudo code

int dfs(beginWord, endWord, hash_words)
    if (new word == end word) return steps num
    
    min_steps = 0
    
    for letter in beginWord
        for char in alphabet
            check if substituted word exist 
                if this word not taken already in hash words
                    check in hash words as taken
                    if !min_steps
                        min_steps = dfs(new word, end word, wordlist, hash_words)
                    else min_steps = min(min_steps, dfs)
*/

#define ALPHABET_SIZE 26

class Solution {
public:
        
    int dfs(string curr_word, string end_word, map<string, bool>& hash_words) {
        
        if (curr_word == end_word) return 0;
        
        int min_steps = INT_MAX;
        int steps = 0;
        for (int i = 0; i < curr_word.size(); ++i) {
            for (char j = 'a'; j <= 'z'; ++j) {
                string temp_word = curr_word;
                if (curr_word[i] != j) {
                    curr_word[i] = j;
                    if (hash_words.count(curr_word) && !hash_words[curr_word]) {
                        hash_words[curr_word] = true;
                        return dfs(curr_word, end_word, hash_words) + 1;
                    }
                    curr_word = temp_word;
                }
            }
        }
        return 0;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, bool> hash_words;
        for (string word: wordList) {
            hash_words[word] = false;
        }
        if (hash_words.count(beginWord)) hash_words[beginWord] = true;
        
        if(!hash_words.count(endWord)) return 0;
        
        return dfs(beginWord, endWord, hash_words);
    }
};

