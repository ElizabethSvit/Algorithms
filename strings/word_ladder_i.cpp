/*
Leetcode task from https://leetcode.com/problems/word-ladder/description/

Pseudo code (DFS):

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
  
Pseudo code (BFS):

int bfs(beginWord, endWord, wordList)
    queue<string> q to store word 
    q <- beginWord, 0
    level = 0
    while q is not empty:
        for i in q size:
            current word = q.top
            q.pop
            if current word == end word
                return level + 1
            for char in alphabet:  
                for letter in word letters:
                    temp word = curr word
                    temp word[letter] = ch
                    if temp word != curr word and temp word is in list:
                        remove temp word from list
                        q <- temp word
        level++
          
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
        set<string> word_set;
        for (string word: wordList) {
            word_set.insert(word);
        }
        
        if(word_set.find(endWord) == word_set.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int level = 0;
        
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; ++i) {
                string curr_word = q.front();
                q.pop();
                
                if (curr_word == endWord) return level + 1;
                
                for (int i = 0; i < curr_word.size(); ++i) {
                    for (char j = 'a'; j <= 'z'; ++j) {
                        string temp_word = curr_word;
                        temp_word[i] = j;
                        if (temp_word != curr_word && word_set.find(temp_word) != word_set.end()) {
                            word_set.erase(temp_word);
                            q.push(temp_word);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};

