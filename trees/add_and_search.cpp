/*
Leetcode task from https://leetcode.com/problems/add-and-search-word-data-structure-design/description/

Approach for data structure: Trie as a Word Dictionary
*/

class TrieNode {
    const static int ALPHABET_SIZE = 26;
    TrieNode* children[ALPHABET_SIZE];
    bool is_end_of_word;
public:
    
    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
        is_end_of_word = false;
    }
    
    void add(string word, int index) {
        if (index == word.length()) {
            is_end_of_word = true;
            return;
        }
        
        int char_index = word[index] - 'a';
        if (!children[char_index]) children[char_index] = new TrieNode();
        children[char_index]->add(word, index+1);
    }

    bool search(string word, int index) {
        if (index == word.length()) return is_end_of_word;
        
        // int char_index;
        if (word[index] != '.') {
            int char_index = word[index] - 'a';
            if (!children[char_index]) return false;
            
            return children[char_index]->search(word, index+1);
        }
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (children[i] && children[i]->search(word, index+1)) return true;
        }
        return false;
    }
    
};

class WordDictionary {
    TrieNode* root;
public:
        
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        root->add(word, 0);
    }
    
    /** Returns if the word is in the data structure. 
    A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return root->search(word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

