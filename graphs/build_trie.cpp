/*
Leetcode task from https://leetcode.com/problems/implement-trie-prefix-tree/description/

Pseudo code

insert(word):
    Trie curr_node = root
    for ch in word
        if (!curr_node->children[ch])
            curr_node->children[ch] = new Trie
        curr_node=curr_node->children[ch]
    curr_node->end = true

search(word):
    Trie curr_node = root
    for ch in word
        if (!curr_node->children[ch]) return false
        curr_node=curr_node->children[ch]
    return curr_node->end
    
startsWith(word):
    Trie curr_node = root
    for ch in word
        if (!curr_node->children[ch]) return false
        curr_node=curr_node->children[ch]
    return true
*/

class TrieNode {
private:
    // static const int ALPHABET_SIZE = 26;
    TrieNode* root;
    TrieNode* children[26];
    bool endOfWord;
public:
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        
        endOfWord = false;
    }
    
    bool containsKey(char ch) {
        return children[ch - 'a'] != nullptr;
    }
    
    void set(char ch, TrieNode* node) {
        children[ch - 'a'] = node;
    }
    
    TrieNode* get(char ch) {
        return children[ch - 'a'];
    }
    
    void setEnd() {
        endOfWord = true;
    }
    
    bool isEnd() {
        return endOfWord;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr_node = root;
        for (char ch: word) {
            // cout << ch << " " << ch - 'a' << " " << curr_node << endl;
            if (!curr_node->containsKey(ch)) curr_node->set(ch, curr_node);
            curr_node=curr_node->get(ch);
        }
        curr_node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr_node = root;
        for (char ch: word) {
            if (!curr_node->containsKey(ch)) return false;
            curr_node=curr_node->get(ch);
        }
        return curr_node->isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr_node = root;
        for (char ch: prefix) {
            if (!curr_node->containsKey(ch)) return false;
            curr_node=curr_node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */

