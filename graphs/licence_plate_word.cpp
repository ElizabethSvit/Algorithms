/*
 
 Google GetAhead program task for week 6
 
 We look at car licence plates and try to find a word from the dictionary
 that includes all the letters from the licence plate. The shorter the word, the better.
 The licence plates start with two or three letters, then they are followed by 5 characters,
 from which at most 2 are letters, the rest are digits.
 
 Write code that will find the shortest words for 1000 licence plates.
 You are given a dictionary. e.g. for the licence plate "RT 123SO"
 the shortest word would be "SORT", for "RC 10014": "CAR".
 
 A few things to clarify:
 - Keep duplicate letters
 - Ordering is irrelevant
 - Case is irrelevant
 - The dictionary is sorted lexicographically
 - The dictionary contains about 4 million entries
 
 During interviews we evaluate candidates on their ability to step through
 their code with examples/tests in order to verify their solution and fix bugs.
 We have provided you with a few examples/tests to start with.
 
 Test Cases
 For the licence plate "RT 123SO" the shortest word would be "SORT"
 For "RC 10014", the shortest word is "CAR".
 
 Pseudo code:
 
 1. get rid of unuseful numbers
 
 2. find in dictionary:
    - make a Trie out of the dictionary
    - check if original word (or its permutation) is in dict
    - add one dot (regular exression) to the word and check again
    - if found -> return the length of the current expression
 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define ALPHABET_SIZE 26

class Trie {
private:
    Trie* children[ALPHABET_SIZE];
    bool isEnd;

public:
    Trie () {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char ch: word) {
            if (!node->children[ch - 'a']) node->children[ch - 'a'] = new Trie();
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }

    bool search(Trie* node, string word) {
        if (!word.length()) return node->isEnd;

        char ch = word[0];
        bool found = false;
        
        if (ch == '.') {
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                if (node->children[i]) found += search(node->children[i], word.substr(1));
            }
            return found;
        } else {
            if (!node->children[ch - 'a']) return false;
            return search(node->children[ch - 'a'], word.substr(1));
        }
        return false;
    }
    
    void printTrie(Trie* root, int level) {
        cout << "All the tree layers:" << endl;
        
        queue<pair<Trie*, int>> q;
        q.push(make_pair(root, 0));
        
        while (!q.empty()) {
            Trie* node = q.front().first;
            int level = q.front().second;
            
            q.pop();
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                if (node->children[i]) {
                    cout << char(i + 'a') << " " << level << endl;
                    q.push(make_pair(node->children[i], level+1));
                } else continue;
            }
        }
    }
};

string extract_letters(string licence_plate) {
    licence_plate.erase(remove_if(licence_plate.begin(), licence_plate.end(),
                                  [](char c) { return !isalpha(c);}), licence_plate.end());
    transform(licence_plate.begin(), licence_plate.end(), licence_plate.begin(), ::tolower);
    return licence_plate;
}

void get_all_permutations(string word, string curr_perm, vector<string> &permutations) {
    if (!word.length()) {
        permutations.push_back(curr_perm);
        return;
    }
    
    for (int i = 0; i < word.length(); ++i) {
        string temp = word;
        temp.erase(temp.begin() + i);
        get_all_permutations(temp, curr_perm+word[i], permutations);
    }
    return;
}

int min_letters(string word, Trie* root) {
    vector<std::string> permutations;
    get_all_permutations(word, "", permutations);
    
    for (string p: permutations) {
        if (root->search(root, p)) return static_cast<int>(word.length());
    }
    
    int dots_num = 0;
    while (dots_num < 100) {
        word += '.';
        get_all_permutations(word, "", permutations);
        for (string p: permutations) {
            if (root->search(root, p)) return static_cast<int>(word.length());
        }
        dots_num++;
    }
    return -1;
}

void fill_the_dict(vector<string> &bunch_of_words, Trie* root) {
    for (string word: bunch_of_words) {
        root->insert(word);
    }
}

int main(int argc, const char * argv[]) {
    Trie* root = new Trie();
    vector<string> bunch_of_words = {"card", "cat", "sort", "car"};
    fill_the_dict(bunch_of_words, root);
    root->printTrie(root, 0);

    string licence_plate = "CR 01423";
    string word = extract_letters(licence_plate);
    cout << min_letters(word, root);
    
    return 0;
}
